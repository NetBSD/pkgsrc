# $NetBSD: Makefile,v 1.35 2023/06/06 12:41:54 riastradh Exp $

DISTNAME=	bulk-small-20230601
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dholland@NetBSD.org
COMMENT=	Meta-package for a standard short limited bulk build

META_PACKAGE=	yes

RESTRICTED=		Just for test build purpose
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

PYTHON_VERSIONS_INCOMPATIBLE=	27

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
# TOOL_DEPENDS logic here will cause more or less useless packages to be
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
TOOL_DEPENDS+=	ircII-[0-9]*:../../chat/ircII
TOOL_DEPENDS+=	irssi-[0-9]*:../../chat/irssi
TOOL_DEPENDS+=	irssi-icb-[0-9]*:../../chat/irssi-icb
TOOL_DEPENDS+=	weechat-[0-9]*:../../chat/weechat
TOOL_DEPENDS+=	base64-[0-9]*:../../converters/base64
TOOL_DEPENDS+=	mpack-[0-9]*:../../converters/mpack
TOOL_DEPENDS+=	emacs21>=21<22:../../editors/emacs21
TOOL_DEPENDS+=	nano-[0-9]*:../../editors/nano
TOOL_DEPENDS+=	vim-[0-9]*:../../editors/vim
TOOL_DEPENDS+=	vim-share-[0-9]*:../../editors/vim-share
TOOL_DEPENDS+=	mutt>=1.5:../../mail/mutt
TOOL_DEPENDS+=	procmail-[0-9]*:../../mail/procmail
TOOL_DEPENDS+=	screen-[0-9]*:../../misc/screen
TOOL_DEPENDS+=	rsync-[0-9]*:../../net/rsync
TOOL_DEPENDS+=	wget-[0-9]*:../../net/wget
TOOL_DEPENDS+=	pkg_chk-[0-9]*:../../pkgtools/pkg_chk
TOOL_DEPENDS+=	pkg_rolling-replace-[0-9]*:../../pkgtools/pkg_rolling-replace
TOOL_DEPENDS+=	pkgin-[0-9]*:../../pkgtools/pkgin
TOOL_DEPENDS+=	enscript-[0-9]*:../../print/enscript
TOOL_DEPENDS+=	ghostscript-gpl-[0-9]*:../../print/ghostscript-gpl
TOOL_DEPENDS+=	papersize-[0-9]*:../../print/papersize
TOOL_DEPENDS+=	${PYPKGPREFIX}-pspdfutils-[0-9]*:../../print/py-pspdfutils
TOOL_DEPENDS+=	sudo-[0-9]*:../../security/sudo
TOOL_DEPENDS+=	stunnel-[0-9]*:../../security/stunnel
TOOL_DEPENDS+=	bash-[0-9]*:../../shells/bash
TOOL_DEPENDS+=	tcsh-[0-9]*:../../shells/tcsh
TOOL_DEPENDS+=	zsh-[0-9]*:../../shells/zsh
TOOL_DEPENDS+=	icewm>=1.2<1.3:../../wm/icewm
TOOL_DEPENDS+=	fluxbox-[0-9]*:../../wm/fluxbox
TOOL_DEPENDS+=	apache>=2.4:../../www/apache24
TOOL_DEPENDS+=	bozohttpd-[0-9]*:../../www/bozohttpd
TOOL_DEPENDS+=	curl-[0-9]*:../../www/curl
TOOL_DEPENDS+=	xlockmore-lite-[0-9]*:../../x11/xlockmore-lite

#
# 2. Base packages for the very popular languages that enormous
# numbers of other packages depend on.
#
TOOL_DEPENDS+=	perl>=5:../../lang/perl5
TOOL_DEPENDS+=	python38-[0-9]*:../../lang/python38

#
# 3. Archivers and build tools.
#
TOOL_DEPENDS+=		bsdtar-[0-9]*:../../archivers/bsdtar
TOOL_DEPENDS+=		bzip2-[0-9]*:../../archivers/bzip2
TOOL_DEPENDS+=		gtar-base-[0-9]*:../../archivers/gtar-base
TOOL_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
TOOL_DEPENDS+=		xz-[0-9]*:../../archivers/xz
TOOL_DEPENDS+=		zip-[0-9]*:../../archivers/zip
TOOL_DEPENDS+=		autoconf-[0-9]*:../../devel/autoconf
TOOL_DEPENDS+=		automake-[0-9]*:../../devel/automake
TOOL_DEPENDS+=		bison-[0-9]*:../../devel/bison
TOOL_DEPENDS+=		flex-[0-9]*:../../devel/flex
TOOL_DEPENDS+=		gmake-[0-9]*:../../devel/gmake
TOOL_DEPENDS+=		libtool-base-[0-9]*:../../devel/libtool-base
TOOL_DEPENDS+=		m4-[0-9]*:../../devel/m4
#TOOL_DEPENDS+=	osabi-[0-9]*:../../pkgtools/osabi
TOOL_DEPENDS+=		pkg_tarup-[0-9]*:../../pkgtools/pkg_tarup

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "native"
TOOL_DEPENDS+=	x11-links-[0-9]*:../../pkgtools/x11-links
.endif

#
# 4. Core widely-used libraries.
#
TOOL_DEPENDS+=	libiconv-[0-9]*:../../converters/libiconv
TOOL_DEPENDS+=	db4-[0-9]*:../../databases/db4
TOOL_DEPENDS+=	gdbm-[0-9]*:../../databases/gdbm
TOOL_DEPENDS+=	sqlite3-[0-9]*:../../databases/sqlite3
TOOL_DEPENDS+=	gettext-lib-[0-9]*:../../devel/gettext-lib
TOOL_DEPENDS+=	readline-[0-9]*:../../devel/readline
TOOL_DEPENDS+=	zlib-[0-9]*:../../devel/zlib
TOOL_DEPENDS+=	gd-[0-9]*:../../graphics/gd
TOOL_DEPENDS+=	giflib-[0-9]*:../../graphics/giflib
.include "../../mk/jpeg.buildlink3.mk"
BUILDLINK_DEPMETHOD.${JPEG_DEFAULT}=	build
TOOL_DEPENDS+=	png-[0-9]*:../../graphics/png
TOOL_DEPENDS+=	tiff-[0-9]*:../../graphics/tiff
TOOL_DEPENDS+=	gnutls-[0-9]*:../../security/gnutls
TOOL_DEPENDS+=	expat-[0-9]*:../../textproc/expat
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	xmlcatmgr-[0-9]*:../../textproc/xmlcatmgr

#
# 5. Depends.
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
TOOL_DEPENDS+=	lzo-[0-9]*:../../archivers/lzo		# required by gnutls
TOOL_DEPENDS+=	gmp-[0-9]*:../../devel/gmp		# required by nettle
TOOL_DEPENDS+=	libcfg+-[0-9]*:../../devel/libcfg+	# required by gnutls
TOOL_DEPENDS+=	libffi-[0-9]*:../../devel/libffi	# required by python
TOOL_DEPENDS+=	libidn-[0-9]*:../../devel/libidn	# required by curl
TOOL_DEPENDS+=	ghostscript-fonts-[0-9]*:../../fonts/ghostscript-fonts
							# req'd by ghostscript
TOOL_DEPENDS+=	f2c-[0-9]*:../../lang/f2c		# req'd by libtool-base
TOOL_DEPENDS+=	libpaper-[0-9]*:../../print/libpaper	# req'd by ghostscript
TOOL_DEPENDS+=	libgcrypt-[0-9]*:../../security/libgcrypt # required by libxslt
TOOL_DEPENDS+=	libgpg-error-[0-9]*:../../security/libgpg-error
							# required by libgcrypt
TOOL_DEPENDS+=	libtasn1-[0-9]*:../../security/libtasn1	# required by gnutls
TOOL_DEPENDS+=	nettle-[0-9]*:../../security/nettle	# required by gnutls

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
