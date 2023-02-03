# $NetBSD: options.mk,v 1.3 2023/02/03 13:00:37 nikita Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnunet

PKG_SUPPORTED_OPTIONS+=		doc idn mysql pgsql tests
PKG_SUPPORTED_OPTIONS+=		experimental pulseaudio
PKG_SUPPORTED_OPTIONS+=		opus ogg sqlite3 audio
PKG_SUPPORTED_OPTIONS+=		gstreamer perl verbose-logging
PKG_SUPPORTED_OPTIONS+=		latex-generate

PKG_SUGGESTED_OPTIONS+=		audio gstreamer opus ogg
PKG_SUGGESTED_OPTIONS+=		idn doc sqlite3 latex-generate

# bluez is still in pkgsrc-wip, and I should test this
# before claiming bluez from pkgsrc-wip on Linux works.
# However, this is a supported option for GNUnet.
# gnunet-qr needs zbar with video support. v4l2 only works
# on Linux. v4l2 on NetBSD needs some work for zbar maybe?
# Furthermore we need to start building zbar with video support
# for this to work on any system.
#.if ${OPSYS} == "Linux"
#PKG_SUPPORTED_OPTIONS+=		bluez zbar
# outdated package, update the package in wip
# PKG_SUGGESTED_OPTIONS+=		bluez
#PKG_SUGGESTED_OPTIONS+=		zbar
#.endif

# We use several PLIST files, as the build process is
# rather lengthy, and keeping it in one file for every
# option is not easy on the one doing the updates.
PLIST_SRC=			PLIST

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mtests}
.include "../../lang/python/tool.mk"
PYTHON_FOR_BUILD_ONLY=	yes
CONFIGURE_ARGS+=	--enable-testruns
.else
CONFIGURE_ARGS+=	--disable-testruns
.endif

# \XXX: 7 MB in size, but useful (although we could strip off some files).
.if ${PKG_OPTIONS:Mdoc}
.include "../../lang/python/tool.mk"
TOOL_DEPENDS+=		${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+=		${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils
CONFIGURE_ARGS+=	--enable-documentation
PLIST_SRC+=		PLIST.doc
INFO_FILES=yes
.else
CONFIGURE_ARGS+=	--disable-documentation
.endif

# gnunet-bcd
PLIST_VARS+=	latex
.if ${PKG_OPTIONS:Mlatex-generate}
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-qrcode-[0-9]*:../../graphics/tex-qrcode
DEPENDS+=	tex-labels-[0-9]*:../../print/tex-labels
PLIST.latex=	yes
.endif

# idn is mandatory but idn or idn2 can be used with a preference for
# idn2.
.if ${PKG_OPTIONS:Midn}
.include "../../devel/libidn2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn2}
.else
.include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn}
.endif

# database support - they don't exclude other databases,
# you can have mysql, pgsql, and the default all built in.
# ideally we would check for at least sqlite3 existing, but
# the build won't build when you have none of them.
.if ${PKG_OPTIONS:Msqlite3}
.include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
PLIST_SRC+=		PLIST.sqlite3
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif

.if ${PKG_OPTIONS:Mmysql}
.include "../../databases/mysql80-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ENV+=		MYSQL_LIBDIR=${BUILDLINK_PREFIX.mysql-client}/lib
PLIST_SRC+=		PLIST.mysql
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PKG_OPTIONS:Mpgsql}
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgresql=yes
PLIST_SRC+=		PLIST.pgsql
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

.if ${PKG_OPTIONS:Mexperimental}
CONFIGURE_ARGS+=	--enable-experimental
PLIST_SRC+=		PLIST.experimental
.  if ${PKG_OPTIONS:Mverbose-logging}
CONFIGURE_ARGS+=	--enable-logging=verbose
.  endif
.else
CONFIGURE_ARGS+=	--disable-experimental
.endif

# conversation submodule. if gstreamer + opus + ogg
# exists, pulseaudio is not necessary. gnunet-gtk
# conditionally builds a binary if the conversation
# submodule is build by gnunet.
.if ${PKG_OPTIONS:Maudio}
.  if ${PKG_OPTIONS:Mopus}
.include "../../audio/libopus/buildlink3.mk"
CONFIGURE_ARGS+=	--with-opus=${BUILDLINK_PREFIX.libopus}
PLIST_SRC+=		PLIST.conversations
.  else
CONFIGURE_ARGS+=	--without-opus
.  endif

.  if ${PKG_OPTIONS:Mogg}
.include "../../multimedia/libogg/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ogg=${BUILDLINK_PREFIX.libogg}
PLIST_SRC+=		PLIST.conversations
.  else
CONFIGURE_ARGS+=	--without-ogg
.  endif

.  if ${PKG_OPTIONS:Mgstreamer}
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
PLIST_SRC+=		PLIST.conversations
.  endif

.  if ${PKG_OPTIONS:Mpulseaudio}
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pulse=${BUILDLINK_PREFIX.pulseaudio}
PLIST_SRC+=		PLIST.conversations
.  else
CONFIGURE_ARGS+=	--without-pulse
.  endif
.endif

#.if ${PKG_OPTIONS:Mzbar}
#.include "../../graphics/zbar/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-zbar=${BUILDLINK_PREFIX.zbar}
#PLIST.zbar=		yes
#.else
#CONFIGURE_ARGS+=	--without-zbar
#.endif

# FIXME: It would be good to provide a build of gnunet against
# 'gnutls build against libdane/unbound' iff unbound is selected,
# causing consequentially a build of gnutls with this setting.
# Since gnunet does build against either of these and gnutls
# without libdane is more common in pkgsrc, this should be
# an option. The conditional below doesn't work.
# .if !empty(PKG_OPTIONS:Munbound) && empty(PKG_BUILD_OPTIONS.gnutls:Munbound)
# PKG_FAIL_REASON+=	"Requires the unbound option enabled in gnutls"
# .endif

# \XXX: last time I tried to build it on Linux, bluez failed to build
#.if ${OPSYS} == "Linux" && ${PKG_OPTIONS:Mbluez}
# Do we need more for bluez?
#.include "../../wip/bluez-libs/buildlink3.mk"
#CONFIGURE_ARGS+=	--with-libbluetooth=${BUILDLINK_PREFIX.bluez-libs}
#PLIST.bluez=		yes
#.endif

# \todo: there are files which only exist on Linux, only on FreeBSD,
# and on both of them.  I have neither of them. If you do, please
# create the appropriate PLIST files with content.

PLIST_VARS+=		perl
# Fix the perl path
.if ${PKG_OPTIONS:Mperl}
PLIST.perl=		yes
USE_TOOLS+=		perl:run
CONFIGURE_ARGS+=	--with-gnunet-logread
REPLACE_INTERPRETER+=	envperl
REPLACE.envperl.old=	.*@PERLEXE@
REPLACE.envperl.new=	${PERL5}
REPLACE_FILES.envperl=	contrib/scripts/gnunet-logread/gnunet-logread-ipc-sdedit.in
REPLACE_FILES.envperl=	contrib/scripts/gnunet-logread/gnunet-logread.in
.endif
