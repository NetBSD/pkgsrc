# $NetBSD: Makefile,v 1.42 2023/09/16 00:35:22 dholland Exp $

DISTNAME=	bulk-small-20230601
PKGREVISION=	1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dholland@NetBSD.org
COMMENT=	Meta-package for a standard short limited bulk build

META_PACKAGE=	yes

RESTRICTED=		Just for test build purpose
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

#
# Note: The purpose of this package is to produce a small set of the
# most generally useful packages in a short time. On a fast build
# machine this whole meta-package should build in less than an
# hour. This gives it a fighting chance of being useful on slow
# platforms.
#
# Please don't arbitrarily add your favorite software in here, or
# on the other hand remove packages just because you don't consider
# them useful in your circumstances.
#
# Candidates for addition (or removal) should be discussed on
# tech-pkg. Undiscussed alterations will be reverted.
#
# If you aren't sure about why some particular package is or is not
# included, please ask.
#

#
# XXX: A few of these packages are commonly built in. The simple
# DEPENDS logic here will cause more or less useless packages to be
# built anyway and then not used, which is a waste of build cycles. It
# would be good to figure out a way to fix this so these packages only
# get built when they aren't builtin.
#
# That applies to these packages:
#    wget  bzip2  xz
#    libiconv  sqlite3  gettext-lib  readline  zlib  expat
#

#
# 1. Applications. These should be either very small or very widely used,
# or preferably both; all others should go in bulk-medium.
#
# Please do not "fix" the emacs reference by updating it to emacs23 or
# newer, as those versions of emacs take longer to build than this
# entire package's time budget.
#
DEPENDS+=	ircII-[0-9]*:../../chat/ircII
DEPENDS+=	irssi-[0-9]*:../../chat/irssi
DEPENDS+=	irssi-icb-[0-9]*:../../chat/irssi-icb
DEPENDS+=	weechat-[0-9]*:../../chat/weechat
DEPENDS+=	base64-[0-9]*:../../converters/base64
DEPENDS+=	mpack-[0-9]*:../../converters/mpack
DEPENDS+=	emacs21>=21<22:../../editors/emacs21
DEPENDS+=	nano-[0-9]*:../../editors/nano
DEPENDS+=	vim-[0-9]*:../../editors/vim
DEPENDS+=	vim-share-[0-9]*:../../editors/vim-share
DEPENDS+=	mutt>=1.5:../../mail/mutt
DEPENDS+=	procmail-[0-9]*:../../mail/procmail
DEPENDS+=	screen-[0-9]*:../../misc/screen
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	wget-[0-9]*:../../net/wget
DEPENDS+=	pkg_chk-[0-9]*:../../pkgtools/pkg_chk
DEPENDS+=	pkg_rolling-replace-[0-9]*:../../pkgtools/pkg_rolling-replace
DEPENDS+=	pkgin-[0-9]*:../../pkgtools/pkgin
DEPENDS+=	enscript-[0-9]*:../../print/enscript
DEPENDS+=	ghostscript-gpl-[0-9]*:../../print/ghostscript-gpl
DEPENDS+=	papersize-[0-9]*:../../print/papersize
DEPENDS+=	sudo-[0-9]*:../../security/sudo
DEPENDS+=	stunnel-[0-9]*:../../security/stunnel
DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	tcsh-[0-9]*:../../shells/tcsh
DEPENDS+=	zsh-[0-9]*:../../shells/zsh
DEPENDS+=	icewm>=1.2<1.3:../../wm/icewm
DEPENDS+=	fluxbox-[0-9]*:../../wm/fluxbox
DEPENDS+=	apache>=2.4:../../www/apache24
DEPENDS+=	bozohttpd-[0-9]*:../../www/bozohttpd
DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	xlockmore-lite-[0-9]*:../../x11/xlockmore-lite

#
# 2. Base packages for the very popular languages that enormous
# numbers of other packages depend on.
#
DEPENDS+=	perl>=5:../../lang/perl5
DEPENDS+=	python311-[0-9]*:../../lang/python311

#
# 3. Archivers and build tools.
#
DEPENDS+=	bsdtar-[0-9]*:../../archivers/bsdtar
DEPENDS+=	bzip2-[0-9]*:../../archivers/bzip2
DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	xz-[0-9]*:../../archivers/xz
DEPENDS+=	zip-[0-9]*:../../archivers/zip
DEPENDS+=	autoconf-[0-9]*:../../devel/autoconf
DEPENDS+=	automake-[0-9]*:../../devel/automake
DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	flex-[0-9]*:../../devel/flex
DEPENDS+=	gmake-[0-9]*:../../devel/gmake
DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base
DEPENDS+=	m4-[0-9]*:../../devel/m4
#DEPENDS+=	osabi-[0-9]*:../../pkgtools/osabi
DEPENDS+=	pkg_tarup-[0-9]*:../../pkgtools/pkg_tarup

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "native"
DEPENDS+=	x11-links-[0-9]*:../../pkgtools/x11-links
.endif

#
# 4. Core widely-used libraries.
#
DEPENDS+=	libiconv-[0-9]*:../../converters/libiconv
DEPENDS+=	db4-[0-9]*:../../databases/db4
DEPENDS+=	gdbm-[0-9]*:../../databases/gdbm
DEPENDS+=	sqlite3-[0-9]*:../../databases/sqlite3
DEPENDS+=	gettext-lib-[0-9]*:../../devel/gettext-lib
DEPENDS+=	readline-[0-9]*:../../devel/readline
DEPENDS+=	zlib-[0-9]*:../../devel/zlib
DEPENDS+=	giflib-[0-9]*:../../graphics/giflib
.include "../../mk/jpeg.buildlink3.mk"
BUILDLINK_DEPMETHOD.${JPEG_DEFAULT}=	build
DEPENDS+=	png-[0-9]*:../../graphics/png
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff
DEPENDS+=	gnutls-[0-9]*:../../security/gnutls
DEPENDS+=	expat-[0-9]*:../../textproc/expat
DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
DEPENDS+=	xmlcatmgr-[0-9]*:../../textproc/xmlcatmgr

#
# 5. Transitive depends.
#
# These additional packages are required by the ones above and are
# listed here for completeness. They might not by themselves really
# be important enough to include in this package rather than one of
# the larger bulk metapackages.
#
# Note that X11 depends aren't included here. This package was laid
# out for native X11; it will of course work for pkgsrc X11 also but
# take somewhat longer.
#
TRANSITIVE+=	lzo-[0-9]*:../../archivers/lzo		# required by gnutls
TRANSITIVE+=	gmp-[0-9]*:../../devel/gmp		# required by nettle
TRANSITIVE+=	libcfg+-[0-9]*:../../devel/libcfg+	# required by gnutls
TRANSITIVE+=	libffi-[0-9]*:../../devel/libffi	# required by python
TRANSITIVE+=	libidn-[0-9]*:../../devel/libidn	# required by curl
TRANSITIVE+=	ghostscript-fonts-[0-9]*:../../fonts/ghostscript-fonts
							# req'd by ghostscript
TRANSITIVE+=	f2c-[0-9]*:../../lang/f2c		# req'd by libtool-base
TRANSITIVE+=	libpaper-[0-9]*:../../print/libpaper	# req'd by ghostscript
TRANSITIVE+=	libgcrypt-[0-9]*:../../security/libgcrypt # required by libxslt
TRANSITIVE+=	libgpg-error-[0-9]*:../../security/libgpg-error
							# required by libgcrypt
TRANSITIVE+=	libtasn1-[0-9]*:../../security/libtasn1	# required by gnutls
TRANSITIVE+=	nettle-[0-9]*:../../security/nettle	# required by gnutls

# Provide a way to hide these when doing dependency analysis.
.if !defined(SUPPRESS_TRANSITIVE)
DEPENDS+=	${TRANSITIVE}
.endif

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
