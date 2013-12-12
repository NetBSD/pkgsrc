# $NetBSD: Makefile,v 1.9 2013/12/12 13:27:17 jperkin Exp $

DISTNAME=	bulk-small-20130316
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
# BUILD_DEPENDS logic here will cause more or less useless packages to be
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
BUILD_DEPENDS+=	ircII-[0-9]*:../../chat/ircII
BUILD_DEPENDS+=	irssi-[0-9]*:../../chat/irssi
BUILD_DEPENDS+=	irssi-icb-[0-9]*:../../chat/irssi-icb
BUILD_DEPENDS+=	weechat-[0-9]*:../../chat/weechat
BUILD_DEPENDS+=	base64-[0-9]*:../../converters/base64
BUILD_DEPENDS+=	mpack-[0-9]*:../../converters/mpack
BUILD_DEPENDS+=	emacs24>=24<25:../../editors/emacs24
BUILD_DEPENDS+=	nano-[0-9]*:../../editors/nano
BUILD_DEPENDS+=	vim-[0-9]*:../../editors/vim
BUILD_DEPENDS+=	vim-share-[0-9]*:../../editors/vim-share
BUILD_DEPENDS+=	mutt>=1.5:../../mail/mutt-devel
BUILD_DEPENDS+=	procmail-[0-9]*:../../mail/procmail
BUILD_DEPENDS+=	screen-[0-9]*:../../misc/screen
BUILD_DEPENDS+=	rsync-[0-9]*:../../net/rsync
BUILD_DEPENDS+=	wget-[0-9]*:../../net/wget
BUILD_DEPENDS+=	pkg_chk-[0-9]*:../../pkgtools/pkg_chk
BUILD_DEPENDS+=	pkg_rolling-replace-[0-9]*:../../pkgtools/pkg_rolling-replace
BUILD_DEPENDS+=	pkgin-[0-9]*:../../pkgtools/pkgin
BUILD_DEPENDS+=	enscript-[0-9]*:../../print/enscript
BUILD_DEPENDS+=	ghostscript-gpl-[0-9]*:../../print/ghostscript-gpl
BUILD_DEPENDS+=	papersize-[0-9]*:../../print/papersize
BUILD_DEPENDS+=	psutils-[0-9]*:../../print/psutils
BUILD_DEPENDS+=	sudo-[0-9]*:../../security/sudo
BUILD_DEPENDS+=	stunnel-[0-9]*:../../security/stunnel
BUILD_DEPENDS+=	bash-[0-9]*:../../shells/bash
BUILD_DEPENDS+=	tcsh-[0-9]*:../../shells/tcsh
BUILD_DEPENDS+=	zsh-[0-9]*:../../shells/zsh
BUILD_DEPENDS+=	icewm-[0-9]*:../../wm/icewm
BUILD_DEPENDS+=	fluxbox-[0-9]*:../../wm/fluxbox
BUILD_DEPENDS+=	fvwm-[0-9]*:../../wm/fvwm
BUILD_DEPENDS+=	apache>=2.2:../../www/apache22
BUILD_DEPENDS+=	bozohttpd-[0-9]*:../../www/bozohttpd
BUILD_DEPENDS+=	curl-[0-9]*:../../www/curl
BUILD_DEPENDS+=	xlockmore-lite-[0-9]*:../../x11/xlockmore-lite

#
# 2. Base packages for the very popular languages that enormous
# numbers of other packages depend on.
#
BUILD_DEPENDS+=	perl>=5:../../lang/perl5
BUILD_DEPENDS+=	python27-[0-9]*:../../lang/python27

#
# 3. Archivers and build tools.
#
BUILD_DEPENDS+=	bsdtar-[0-9]*:../../archivers/bsdtar
BUILD_DEPENDS+=	bzip2-[0-9]*:../../archivers/bzip2
BUILD_DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base
BUILD_DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
BUILD_DEPENDS+=	xz-[0-9]*:../../archivers/xz
BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=	autoconf-[0-9]*:../../devel/autoconf
BUILD_DEPENDS+=	automake-[0-9]*:../../devel/automake
BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=	flex-[0-9]*:../../devel/flex
BUILD_DEPENDS+=	gmake-[0-9]*:../../devel/gmake
BUILD_DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base
BUILD_DEPENDS+=	m4-[0-9]*:../../devel/m4
BUILD_DEPENDS+=	pkg-config-[0-9]*:../../devel/pkg-config
#BUILD_DEPENDS+=	osabi-[0-9]*:../../pkgtools/osabi
BUILD_DEPENDS+=	pkg_tarup-[0-9]*:../../pkgtools/pkg_tarup

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "native"
BUILD_DEPENDS+=	x11-links-[0-9]*:../../pkgtools/x11-links
.endif

#
# 4. Core widely-used libraries.
#
BUILD_DEPENDS+=	libiconv-[0-9]*:../../converters/libiconv
BUILD_DEPENDS+=	db4-[0-9]*:../../databases/db4
BUILD_DEPENDS+=	gdbm-[0-9]*:../../databases/gdbm
BUILD_DEPENDS+=	sqlite3-[0-9]*:../../databases/sqlite3
BUILD_DEPENDS+=	gettext-lib-[0-9]*:../../devel/gettext-lib
BUILD_DEPENDS+=	readline-[0-9]*:../../devel/readline
BUILD_DEPENDS+=	zlib-[0-9]*:../../devel/zlib
BUILD_DEPENDS+=	gd-[0-9]*:../../graphics/gd
BUILD_DEPENDS+=	giflib-[0-9]*:../../graphics/giflib
BUILD_DEPENDS+=	jpeg-[0-9]*:../../graphics/jpeg
BUILD_DEPENDS+=	png-[0-9]*:../../graphics/png
BUILD_DEPENDS+=	tiff-[0-9]*:../../graphics/tiff
BUILD_DEPENDS+=	gnutls-[0-9]*:../../security/gnutls
BUILD_DEPENDS+=	expat-[0-9]*:../../textproc/expat
BUILD_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	xmlcatmgr-[0-9]*:../../textproc/xmlcatmgr

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
BUILD_DEPENDS+=	lzo-[0-9]*:../../archivers/lzo		# required by gnutls
BUILD_DEPENDS+=	apr-[0-9]*:../../devel/apr		# required by apache22
BUILD_DEPENDS+=	apr-util-[0-9]*:../../devel/apr-util	# required by apache22
BUILD_DEPENDS+=	gmp-[0-9]*:../../devel/gmp		# required by nettle
BUILD_DEPENDS+=	libcfg+-[0-9]*:../../devel/libcfg+	# required by gnutls
BUILD_DEPENDS+=	libffi-[0-9]*:../../devel/libffi	# required by python
BUILD_DEPENDS+=	libidn-[0-9]*:../../devel/libidn	# required by curl
BUILD_DEPENDS+=	ghostscript-fonts-[0-9]*:../../fonts/ghostscript-fonts
							# req'd by ghostscript
BUILD_DEPENDS+=	f2c-[0-9]*:../../lang/f2c		# req'd by libtool-base
BUILD_DEPENDS+=	libpaper-[0-9]*:../../print/libpaper	# req'd by ghostscript
BUILD_DEPENDS+=	libgcrypt-[0-9]*:../../security/libgcrypt # required by libxslt
BUILD_DEPENDS+=	libgpg-error-[0-9]*:../../security/libgpg-error
							# required by libgcrypt
BUILD_DEPENDS+=	libtasn1-[0-9]*:../../security/libtasn1	# required by gnutls
BUILD_DEPENDS+=	nettle-[0-9]*:../../security/nettle	# required by gnutls
BUILD_DEPENDS+=	xpmroot-[0-9]*:../../x11/xpmroot	# required by fvwm


.include "../../mk/bsd.pkg.mk"
