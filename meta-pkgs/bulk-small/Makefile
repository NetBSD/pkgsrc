# $NetBSD: Makefile,v 1.53 2023/10/30 12:40:13 nia Exp $

DISTNAME=	bulk-small-20231022
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
DEPENDS+=	papersize-[0-9]*:../../print/papersize
DEPENDS+=	sudo-[0-9]*:../../security/sudo
DEPENDS+=	stunnel-[0-9]*:../../security/stunnel
DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	tcsh-[0-9]*:../../shells/tcsh
DEPENDS+=	zsh-[0-9]*:../../shells/zsh
DEPENDS+=	htop-[0-9]*:../../sysutils/htop
DEPENDS+=	fvwm-[0-9]*:../../wm/fvwm
DEPENDS+=	bozohttpd-[0-9]*:../../www/bozohttpd
DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	lynx-[0-9]*:../../www/lynx
DEPENDS+=	xlockmore-lite-[0-9]*:../../x11/xlockmore-lite

#
# 2. Base packages for the very popular languages that enormous
# numbers of other packages depend on.
#
DEPENDS+=	perl>=5:../../lang/perl5
DEPENDS+=	python311-[0-9]*:../../lang/python311
DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

#
# 3. Archivers and build tools.
#
DEPENDS+=	bsdtar-[0-9]*:../../archivers/bsdtar
DEPENDS+=	bzip2-[0-9]*:../../archivers/bzip2
DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base
DEPENDS+=	unzip-[0-9]*:../../archivers/unzip
DEPENDS+=	xz-[0-9]*:../../archivers/xz
DEPENDS+=	zip-[0-9]*:../../archivers/zip
DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	flex-[0-9]*:../../devel/flex
DEPENDS+=	gmake-[0-9]*:../../devel/gmake
DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base
DEPENDS+=	m4-[0-9]*:../../devel/m4
DEPENDS+=	meson-[0-9]*:../../devel/meson
DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build
DEPENDS+=	pkgconf-[0-9]*:../../devel/pkgconf
# osabi should really be listed explicitly, but its actual PKGNAME varies
# and picking up the right one is not worth the trouble, since x11-links
# pulls it in.
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
DEPENDS+=	glib2-[0-9]*:../../devel/glib2
DEPENDS+=	readline-[0-9]*:../../devel/readline
DEPENDS+=	zlib-[0-9]*:../../devel/zlib
DEPENDS+=	giflib-[0-9]*:../../graphics/giflib
# Note that if you set JPEG_TYPE to libjpeg-turbo you'll also
# end up building cmake.
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
# (Note that it is not necessarily worth spending a lot of effort
# maintaining these lists; however, it is worth keeping at least
# occasional track of what's being pulled in and whether it's
# excessively expensive.)
#

# required by chat/irssi and chat/irssi-icb
TRANSITIVE+=	libotr-[0-9]*:../../chat/libotr
TRANSITIVE+=	libgcrypt-[0-9]*:../../security/libgcrypt	# via libotr
TRANSITIVE+=	libgpg-error-[0-9]*:../../security/libgpg-error	# via libotr
TRANSITIVE+=	glib2-tools-[0-9]*:../../devel/glib2-tools

# required by editors/emacs21
TRANSITIVE+=	tradcpp-[0-9]*:../../devel/tradcpp
TRANSITIVE+=	imake-[0-9]*:../../devel/imake
TRANSITIVE+=	xorg-cf-files-[0-9]*:../../x11/xorg-cf-files	# via imake

# required by mail/mutt
TRANSITIVE+=	help2man-[0-9]*:../../converters/help2man	# via autoconf
TRANSITIVE+=	db4-[0-9]*:../../databases/db4
TRANSITIVE+=	autoconf-[0-9]*:../../devel/autoconf		# via ?
TRANSITIVE+=	libusb1-[0-9]*:../../devel/libusb1		# via gnupg2
TRANSITIVE+=	npth-[0-9]*:../../devel/npth			# via gnupg2
TRANSITIVE+=	p5-gettext-[0-9]*:../../devel/p5-gettext	# via help2man
TRANSITIVE+=	mime-types-[0-9]*:../../misc/mime-types
TRANSITIVE+=	cyrus-sasl-[0-9]*:../../security/cyrus-sasl
TRANSITIVE+=	gpgme-[0-9]*:../../security/gpgme
TRANSITIVE+=	gnupg2-[0-9]*:../../security/gnupg2
TRANSITIVE+=	libassuan>=2:../../security/libassuan2		# via gnupg2
TRANSITIVE+=	libgcrypt-[0-9]*:../../security/libgcrypt	# via gnupg2
TRANSITIVE+=	libgpg-error-[0-9]*:../../security/libgpg-error	# via gnupg2
TRANSITIVE+=	pinentry-[0-9]*:../../security/pinentry		# via gnupg2
TRANSITIVE+=	libksba-[0-9]*:../../security/libksba		# via gnupg2
TRANSITIVE+=	docbook-xml-[0-9]*:../../textproc/docbook-xml
TRANSITIVE+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

# required by misc/screen
TRANSITIVE+=	help2man-[0-9]*:../../converters/help2man	# via autoconf
TRANSITIVE+=	autoconf-[0-9]*:../../devel/autoconf
TRANSITIVE+=	automake-[0-9]*:../../devel/automake
TRANSITIVE+=	p5-gettext-[0-9]*:../../devel/p5-gettext	# via autoconf

# required by net/rsync
TRANSITIVE+=	lz4-[0-9]*:../../archivers/lz4
TRANSITIVE+=	zstd-[0-9]*:../../archivers/zstd
TRANSITIVE+=	popt-[0-9]*:../../devel/popt
TRANSITIVE+=	xxhash-[0-9]*:../../devel/xxhash

# required by net/wget
TRANSITIVE+=	lzip-[0-9]*:../../archivers/lzip		# via libpsl
TRANSITIVE+=	libidn2-[0-9]*:../../devel/libidn2
TRANSITIVE+=	libunistring-[0-9]*:../../textproc/libunistring	# via libidn2
TRANSITIVE+=	libpsl-[0-9]*:../../www/libpsl

# required by pkgtools/pkgin
TRANSITIVE+=	libfetch-[0-9]*:../../net/libfetch

# required by www/bozohttpd
TRANSITIVE+=	lua54-[0-9]*:../../lang/lua54

# required by www/curl
TRANSITIVE+=	libidn2-[0-9]*:../../devel/libidn2
TRANSITIVE+=	libunistring-[0-9]*:../../textproc/libunistring	# via libidn2
TRANSITIVE+=	nghttp2-[0-9]*:../../www/nghttp2

# required by x11/xlockmore-lite
TRANSITIVE+=	help2man-[0-9]*:../../converters/help2man	# via autoconf
TRANSITIVE+=	autoconf-[0-9]*:../../devel/autoconf
TRANSITIVE+=	p5-gettext-[0-9]*:../../devel/p5-gettext	# via autoconf
TRANSITIVE+=	tradcpp-[0-9]*:../../devel/tradcpp		# via imake
TRANSITIVE+=	imake-[0-9]*:../../devel/imake
TRANSITIVE+=	xorg-cf-files-[0-9]*:../../x11/xorg-cf-files	# via imake

# required by lang/python*
TRANSITIVE+=	libffi-[0-9]*:../../devel/libffi
TRANSITIVE+=	libuuid-[0-9]*:../../devel/libuuid

# required by devel/bison
TRANSITIVE+=	gettext-tools-[0-9]*:../../devel/gettext-tools

# required by devel/flex
TRANSITIVE+=	help2man-[0-9]*:../../converters/help2man
TRANSITIVE+=	p5-gettext-[0-9]*:../../devel/p5-gettext

# required by devel/meson
TRANSITIVE+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

# required by devel/ninja-build
TRANSITIVE+=	re2c-[0-9]*:../../devel/re2c

# required by devel/glib2
TRANSITIVE+=	gettext-tools-[0-9]*:../../devel/gettext-tools
TRANSITIVE+=	libffi-[0-9]*:../../devel/libffi
TRANSITIVE+=	pcre2-[0-9]*:../../devel/pcre2

# required by graphics/tiff
TRANSITIVE+=	jbigkit-[0-9]*:../../graphics/jbigkit

# required by security/gnutls
TRANSITIVE+=	autoconf-[0-9]*:../../devel/autoconf		# via ?
TRANSITIVE+=	gettext-tools-[0-9]*:../../devel/gettext-tools
TRANSITIVE+=	libcfg+-[0-9]*:../../devel/libcfg+
TRANSITIVE+=	gmp-[0-9]*:../../devel/gmp
TRANSITIVE+=	libffi-[0-9]*:../../devel/libffi		# via p11-kit
TRANSITIVE+=	libtasn1-[0-9]*:../../security/libtasn1
TRANSITIVE+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts
TRANSITIVE+=	nettle-[0-9]*:../../security/nettle
TRANSITIVE+=	p11-kit-[0-9]*:../../security/p11-kit
TRANSITIVE+=	gsed-[0-9]*:../../textproc/gsed
TRANSITIVE+=	libunistring-[0-9]*:../../textproc/libunistring

# required by textproc/libxslt
TRANSITIVE+=	docbook-xml-[0-9]*:../../textproc/docbook-xml
TRANSITIVE+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TRANSITIVE+=	libgcrypt-[0-9]*:../../security/libgcrypt
TRANSITIVE+=	libgpg-error-[0-9]*:../../security/libgpg-error

# required by wm/fvwm
TRANSITIVE+=	libstroke-[0-9]*:../../devel/libstroke

# Provide a way to hide these when doing dependency analysis.
.if !defined(SUPPRESS_TRANSITIVE)
DEPENDS+=	${TRANSITIVE}
.endif

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
