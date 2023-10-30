# $NetBSD: Makefile,v 1.103 2023/10/30 12:25:15 nia Exp $

DISTNAME=	bulk-medium-20231022
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dholland@NetBSD.org
COMMENT=	Meta-package for a standard medium-sized limited bulk build

META_PACKAGE=	yes

RESTRICTED=		Just for test build purpose
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

#
# Note: the purpose of this package is to produce a useful collection
# of packages in a reasonable period of time. On a fast build machine
# this whole meta-package should build in less than eight hours,
# assuming that bulk-small is already built.
#
# The packages that are listed here are those most widely used, either
# by end users or by other packages. Many popular or useful packages
# are not included here, not because they aren't cool enough, but
# because they are too large to justify the build time, or because
# they just aren't as widely used as others.
#
# Note in particular that while some of the support libraries are in
# here, most "desktop" packages (even fairly widely used ones) are and
# should be in bulk-large.
#
# Please discuss proposed additions (and removals) on tech-pkg.
# Undiscussed changes will be reverted.
#

#
# XXX: There is nothing here from inputmethod/, and there should be.
# Someone please let me know what the most useful/popular things
# there are.
#

.include "../../mk/bsd.prefs.mk"

#
# 0. By design bulk-medium is supposed to be a superset of bulk-small.
# Depend on it rather than duplicating its listings.
#
DEPENDS+=	bulk-small-[0-9]*:../../meta-pkgs/bulk-small

#
# 1. Applications
#
DEPENDS+=	cdparanoia-[0-9]*:../../audio/cdparanoia
DEPENDS+=	flac-[0-9]*:../../audio/flac
DEPENDS+=	flac123-[0-9]*:../../audio/flac123
DEPENDS+=	lame-[0-9]*:../../audio/lame
DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123
DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools
DEPENDS+=	jabberd>=2:../../chat/jabberd2
DEPENDS+=	hexchat-[0-9]*:../../chat/hexchat
DEPENDS+=	weechat-[0-9]*:../../chat/weechat
DEPENDS+=	fribidi-[0-9]*:../../converters/fribidi
DEPENDS+=	mariadb-client>=10.5<10.6:../../databases/mariadb105-client
DEPENDS+=	mariadb-client>=10.6<10.7:../../databases/mariadb106-client
DEPENDS+=	openldap-client-[0-9]*:../../databases/openldap-client
DEPENDS+=	git-[0-9]*:../../devel/git
DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	git-docs-[0-9]*:../../devel/git-docs
DEPENDS+=	mercurial-[0-9]*:../../devel/mercurial
DEPENDS+=	nvi-[0-9]*:../../editors/nvi
DEPENDS+=	vim-gtk3-[0-9]*:../../editors/vim-gtk3
# emacs with x11 also brings in rust, which doesn't fit in this package
DEPENDS+=	emacs-nox11-[0-9]*:../../editors/emacs-nox11
DEPENDS+=	dosbox-[0-9]*:../../emulators/dosbox
DEPENDS+=	simh-[0-9]*:../../emulators/simh
DEPENDS+=	tme-[0-9]*:../../emulators/tme
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
DEPENDS+=	gawk-[0-9]*:../../lang/gawk
DEPENDS+=	php>=7.4<7.5:../../lang/php74
DEPENDS+=	php>=8.0<8.1:../../lang/php80
DEPENDS+=	php>=8.1<8.2:../../lang/php81
DEPENDS+=	php>=8.2<8.3:../../lang/php82
DEPENDS+=	ruby31-base-[0-9]*:../../lang/ruby31-base
DEPENDS+=	ruby32-base-[0-9]*:../../lang/ruby32-base
DEPENDS+=	openjdk8-[0-9]*:../../lang/openjdk8
DEPENDS+=	openjdk11-[0-9]*:../../lang/openjdk11
DEPENDS+=	fetchmail-[0-9]*:../../mail/fetchmail
DEPENDS+=	imap-uw-[0-9]*:../../mail/imap-uw
DEPENDS+=	mailman-[0-9]*:../../mail/mailman
DEPENDS+=	mhonarc-[0-9]*:../../mail/mhonarc
DEPENDS+=	mutt-[0-9]*:../../mail/mutt
DEPENDS+=	alpine-[0-9]*:../../mail/alpine
DEPENDS+=	spamassassin-[0-9]*:../../mail/spamassassin
DEPENDS+=	bind>=9.16<9.17:../../net/bind916
DEPENDS+=	nmap-[0-9]*:../../net/nmap
DEPENDS+=	samba>=4.2:../../net/samba4
DEPENDS+=	wpa_supplicant-[0-9]*:../../net/wpa_supplicant
DEPENDS+=	xymon-[0-9]*:../../net/xymon
DEPENDS+=	xymonclient-[0-9]*:../../net/xymonclient
DEPENDS+=	yt-dlp-[0-9]*:../../net/yt-dlp
DEPENDS+=	lintpkgsrc-[0-9]*:../../pkgtools/lintpkgsrc
DEPENDS+=	pkglint-[0-9]*:../../pkgtools/pkglint
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
DEPENDS+=	mupdf-[0-9]*:../../print/mupdf
DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
DEPENDS+=	desktop-file-utils-[0-9]*:../../sysutils/desktop-file-utils
DEPENDS+=	xe-guest-utilities-[0-9]*:../../sysutils/xe-guest-utilities
.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
DEPENDS+=	xenkernel415-[0-9]*:../../sysutils/xenkernel415
DEPENDS+=	xentools415-[0-9]*:../../sysutils/xentools415
.endif
DEPENDS+=	ispell-[0-9]*:../../textproc/ispell
DEPENDS+=	icewm>=1.2<1.3:../../wm/icewm
DEPENDS+=	fluxbox-[0-9]*:../../wm/fluxbox
DEPENDS+=	apache>=2.4:../../www/apache24
DEPENDS+=	arcticfox-[0-9]*:../../www/arcticfox
DEPENDS+=	xlockmore-[0-9]*:../../x11/xlockmore

#
# 2. Archivers and build tools
#
DEPENDS+=	pigz-[0-9]*:../../archivers/pigz
DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	imake-[0-9]*:../../devel/imake
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
DEPENDS+=	nasm-[0-9]*:../../devel/nasm
DEPENDS+=	yasm-[0-9]*:../../devel/yasm
.endif
DEPENDS+=	icon-naming-utils-[0-9]*:../../graphics/icon-naming-utils

#
# 3. Commonly used libraries
#
DEPENDS+=	SDL2_mixer-[0-9]*:../../audio/SDL2_mixer
DEPENDS+=	opusfile-[0-9]*:../../audio/opusfile
DEPENDS+=	libvorbis-[0-9]*:../../audio/libvorbis
DEPENDS+=	gdbm-[0-9]*:../../databases/gdbm
DEPENDS+=	p5-BDB-[0-9]*:../../databases/p5-BDB
DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	${PYPKGPREFIX}-bsddb3-[0-9]*:../../databases/py-bsddb3
DEPENDS+=	${PYPKGPREFIX}-postgresql-[0-9]*:../../databases/py-postgresql
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
DEPENDS+=	SDL2-[0-9]*:../../devel/SDL2
DEPENDS+=	atk-[0-9]*:../../devel/atk
DEPENDS+=	boehm-gc-[0-9]*:../../devel/boehm-gc
DEPENDS+=	glib2-[0-9]*:../../devel/glib2
DEPENDS+=	libelf-[0-9]*:../../devel/libelf
DEPENDS+=	libf2c-[0-9]*:../../devel/libf2c
DEPENDS+=	libidn2-[0-9]*:../../devel/libidn2
DEPENDS+=	libltdl-[0-9]*:../../devel/libltdl
DEPENDS+=	libusb1-[0-9]*:../../devel/libusb1
DEPENDS+=	ncurses-[0-9]*:../../devel/ncurses
DEPENDS+=	ncursesw-[0-9]*:../../devel/ncursesw
DEPENDS+=	pango-[0-9]*:../../devel/pango
DEPENDS+=	pcre-[0-9]*:../../devel/pcre
DEPENDS+=	popt-[0-9]*:../../devel/popt
DEPENDS+=	fuse-[0-9]*:../../filesystems/fuse
.if ${OPSYS} == "NetBSD"
DEPENDS+=	perfuse-[0-9]*:../../filesystems/perfuse
.endif
DEPENDS+=	SDL2_image-[0-9]*:../../graphics/SDL2_image
DEPENDS+=	cairo-[0-9]*:../../graphics/cairo
DEPENDS+=	gdk-pixbuf2-[0-9]*:../../graphics/gdk-pixbuf2
DEPENDS+=	glew-[0-9]*:../../graphics/glew
DEPENDS+=	openjpeg-[0-9]*:../../graphics/openjpeg
DEPENDS+=	lcms2-[0-9]*:../../graphics/lcms2
.include "../../graphics/librsvg/available.mk"
DEPENDS+=	blas-[0-9]*:../../math/blas
DEPENDS+=	lapack-[0-9]*:../../math/lapack
DEPENDS+=	boost-[0-9]*:../../meta-pkgs/boost
DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4
DEPENDS+=	libogg-[0-9]*:../../multimedia/libogg
DEPENDS+=	libpcap-[0-9]*:../../net/libpcap
DEPENDS+=	poppler-[0-9]*:../../print/poppler
DEPENDS+=	poppler-includes-[0-9]*:../../print/poppler-includes
DEPENDS+=	cyrus-sasl-[0-9]*:../../security/cyrus-sasl
DEPENDS+=	openssl-[0-9]*:../../security/openssl
DEPENDS+=	tcp_wrappers-[0-9]*:../../security/tcp_wrappers
DEPENDS+=	libnotify-[0-9]*:../../sysutils/libnotify
DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3

#
# 4. Linux compat packages
#
.if ${OPSYS} == "NetBSD"
DEPENDS+=	suse>=13.1:../../meta-pkgs/suse131
.endif

#
# 5. Desktop infrastructure and support services
#
DEPENDS+=	eawpatches-[0-9]*:../../audio/eawpatches
DEPENDS+=	shared-mime-info-[0-9]*:../../databases/shared-mime-info
DEPENDS+=	hicolor-icon-theme-[0-9]*:../../graphics/hicolor-icon-theme

#
# 6. Other very small packages
#
DEPENDS+=	${LUA_PKGPREFIX}-stdlib-[0-9]*:../../devel/lua-stdlib

#
# Note that (unlike in bulk-small) we make no effort to list or track
# depends of the above. As long as the total size of this package
# remains roughly what we want, the exact list of depends doesn't
# matter too much.
#

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	27 38
.include "../../lang/lua/luaversion.mk" # for LUA_PKGPREFIX
.include "../../lang/python/pyversion.mk" # for PYPKGPREFIX
.include "../../mk/bsd.pkg.mk"
