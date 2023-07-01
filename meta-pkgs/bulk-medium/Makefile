# $NetBSD: Makefile,v 1.80 2023/07/01 08:35:09 wiz Exp $

DISTNAME=	bulk-medium-20230701
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

#
# 1. Applications
#
TOOL_DEPENDS+=	cdparanoia-[0-9]*:../../audio/cdparanoia
TOOL_DEPENDS+=	flac-[0-9]*:../../audio/flac
TOOL_DEPENDS+=	flac123-[0-9]*:../../audio/flac123
TOOL_DEPENDS+=	lame-[0-9]*:../../audio/lame
TOOL_DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123
TOOL_DEPENDS+=	sox-[0-9]*:../../audio/sox
TOOL_DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools
TOOL_DEPENDS+=	jabberd>=2:../../chat/jabberd2
TOOL_DEPENDS+=	sirc-[0-9]*:../../chat/sirc
TOOL_DEPENDS+=	hexchat-[0-9]*:../../chat/hexchat
TOOL_DEPENDS+=	fribidi-[0-9]*:../../converters/fribidi
TOOL_DEPENDS+=	mariadb-client>=10.5<10.6:../../databases/mariadb105-client
TOOL_DEPENDS+=	mariadb-client>=10.6<10.7:../../databases/mariadb106-client
TOOL_DEPENDS+=	openldap-client-[0-9]*:../../databases/openldap-client
TOOL_DEPENDS+=	git-[0-9]*:../../devel/git
TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TOOL_DEPENDS+=	git-docs-[0-9]*:../../devel/git-docs
TOOL_DEPENDS+=	mercurial-[0-9]*:../../devel/mercurial
TOOL_DEPENDS+=	emacs25>=25<26:../../editors/emacs25
TOOL_DEPENDS+=	emacs-packages-[0-9]*:../../editors/emacs-packages
TOOL_DEPENDS+=	nvi-[0-9]*:../../editors/nvi
TOOL_DEPENDS+=	vim-gtk3-[0-9]*:../../editors/vim-gtk3
TOOL_DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
TOOL_DEPENDS+=	qemu-[0-9]*:../../emulators/qemu
TOOL_DEPENDS+=	simh-[0-9]*:../../emulators/simh
TOOL_DEPENDS+=	tme-[0-9]*:../../emulators/tme
TOOL_DEPENDS+=	wine-[0-9]*:../../emulators/wine
TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
TOOL_DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot
TOOL_DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
TOOL_DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
TOOL_DEPENDS+=	gawk-[0-9]*:../../lang/gawk
TOOL_DEPENDS+=	php>=7.4<7.5:../../lang/php74
TOOL_DEPENDS+=	php>=8.0<8.1:../../lang/php80
TOOL_DEPENDS+=	php>=8.1<8.2:../../lang/php81
TOOL_DEPENDS+=	php>=8.2<8.3:../../lang/php82
TOOL_DEPENDS+=	ruby30-base-[0-9]*:../../lang/ruby30-base
TOOL_DEPENDS+=	ruby31-base-[0-9]*:../../lang/ruby31-base
TOOL_DEPENDS+=	ruby32-base-[0-9]*:../../lang/ruby32-base
TOOL_DEPENDS+=	openjdk8-[0-9]*:../../lang/openjdk8
TOOL_DEPENDS+=	openjdk11-[0-9]*:../../lang/openjdk11
TOOL_DEPENDS+=	python310-[0-9]*:../../lang/python310
TOOL_DEPENDS+=	tcl-[0-9]*:../../lang/tcl
TOOL_DEPENDS+=	fetchmail-[0-9]*:../../mail/fetchmail
TOOL_DEPENDS+=	imap-uw-[0-9]*:../../mail/imap-uw
TOOL_DEPENDS+=	mailman-[0-9]*:../../mail/mailman
TOOL_DEPENDS+=	mhonarc-[0-9]*:../../mail/mhonarc
TOOL_DEPENDS+=	mutt-[0-9]*:../../mail/mutt
TOOL_DEPENDS+=	alpine-[0-9]*:../../mail/alpine
TOOL_DEPENDS+=	spamassassin-[0-9]*:../../mail/spamassassin
TOOL_DEPENDS+=	bind>=9.16<9.17:../../net/bind916
TOOL_DEPENDS+=	clive-[0-9]*:../../net/clive
TOOL_DEPENDS+=	nmap-[0-9]*:../../net/nmap
TOOL_DEPENDS+=	samba>=4.2:../../net/samba4
TOOL_DEPENDS+=	wpa_supplicant-[0-9]*:../../net/wpa_supplicant
TOOL_DEPENDS+=	xymon-[0-9]*:../../net/xymon
TOOL_DEPENDS+=	xymonclient-[0-9]*:../../net/xymonclient
TOOL_DEPENDS+=	youtube-dl-[0-9]*:../../net/youtube-dl
TOOL_DEPENDS+=	lintpkgsrc-[0-9]*:../../pkgtools/lintpkgsrc
TOOL_DEPENDS+=	pkglint-[0-9]*:../../pkgtools/pkglint
TOOL_DEPENDS+=	ghostscript-agpl-[0-9]*:../../print/ghostscript-agpl
TOOL_DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
TOOL_DEPENDS+=	xpdf-[0-9]*:../../print/xpdf
TOOL_DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
TOOL_DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
TOOL_DEPENDS+=	desktop-file-utils-[0-9]*:../../sysutils/desktop-file-utils
TOOL_DEPENDS+=	xe-guest-utilities-[0-9]*:../../sysutils/xe-guest-utilities
TOOL_DEPENDS+=	xenkernel413-[0-9]*:../../sysutils/xenkernel413
TOOL_DEPENDS+=	xentools413-[0-9]*:../../sysutils/xentools413
TOOL_DEPENDS+=	ispell-[0-9]*:../../textproc/ispell
TOOL_DEPENDS+=	seamonkey-[0-9]*:../../www/seamonkey
TOOL_DEPENDS+=	xlockmore-[0-9]*:../../x11/xlockmore

#
# 2. Archivers and build tools
#
TOOL_DEPENDS+=	pigz-[0-9]*:../../archivers/pigz
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	imake-[0-9]*:../../devel/imake
TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
TOOL_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
TOOL_DEPENDS+=	icon-naming-utils-[0-9]*:../../graphics/icon-naming-utils

#
# 3. Commonly used libraries
#
TOOL_DEPENDS+=	SDL2_mixer-[0-9]*:../../audio/SDL2_mixer
TOOL_DEPENDS+=	opusfile-[0-9]*:../../audio/opusfile
TOOL_DEPENDS+=	libvorbis-[0-9]*:../../audio/libvorbis
TOOL_DEPENDS+=	gdbm-[0-9]*:../../databases/gdbm
TOOL_DEPENDS+=	p5-BDB-[0-9]*:../../databases/p5-BDB
TOOL_DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB
TOOL_DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
TOOL_DEPENDS+=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
TOOL_DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
TOOL_DEPENDS+=	${PYPKGPREFIX}-bsddb3-[0-9]*:../../databases/py-bsddb3
TOOL_DEPENDS+=	${PYPKGPREFIX}-gdbm-[0-9]*:../../databases/py-gdbm
TOOL_DEPENDS+=	${PYPKGPREFIX}-postgresql-[0-9]*:../../databases/py-postgresql
TOOL_DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
TOOL_DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
TOOL_DEPENDS+=	SDL2-[0-9]*:../../devel/SDL2
TOOL_DEPENDS+=	atk-[0-9]*:../../devel/atk
TOOL_DEPENDS+=	boehm-gc-[0-9]*:../../devel/boehm-gc
TOOL_DEPENDS+=	glib2-[0-9]*:../../devel/glib2
TOOL_DEPENDS+=	libelf-[0-9]*:../../devel/libelf
TOOL_DEPENDS+=	libf2c-[0-9]*:../../devel/libf2c
TOOL_DEPENDS+=	libidn2-[0-9]*:../../devel/libidn2
TOOL_DEPENDS+=	libltdl-[0-9]*:../../devel/libltdl
TOOL_DEPENDS+=	libusb1-[0-9]*:../../devel/libusb1
TOOL_DEPENDS+=	ncurses-[0-9]*:../../devel/ncurses
TOOL_DEPENDS+=	ncursesw-[0-9]*:../../devel/ncursesw
TOOL_DEPENDS+=	pango-[0-9]*:../../devel/pango
TOOL_DEPENDS+=	pcre-[0-9]*:../../devel/pcre
TOOL_DEPENDS+=	popt-[0-9]*:../../devel/popt
TOOL_DEPENDS+=	fuse-[0-9]*:../../filesystems/fuse
TOOL_DEPENDS+=	perfuse-[0-9]*:../../filesystems/perfuse
TOOL_DEPENDS+=	SDL2_image-[0-9]*:../../graphics/SDL2_image
TOOL_DEPENDS+=	cairo-[0-9]*:../../graphics/cairo
TOOL_DEPENDS+=	gdk-pixbuf2-[0-9]*:../../graphics/gdk-pixbuf2
TOOL_DEPENDS+=	glew-[0-9]*:../../graphics/glew
TOOL_DEPENDS+=	openjpeg-[0-9]*:../../graphics/openjpeg
TOOL_DEPENDS+=	lcms-[0-9]*:../../graphics/lcms
TOOL_DEPENDS+=	lcms2-[0-9]*:../../graphics/lcms2
.include "../../graphics/librsvg/available.mk"
.if ${LIBRSVG_TYPE} == "rust"
TOOL_DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg
.else
TOOL_DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg-c
.endif
TOOL_DEPENDS+=	blas-[0-9]*:../../math/blas
TOOL_DEPENDS+=	lapack-[0-9]*:../../math/lapack
TOOL_DEPENDS+=	boost-[0-9]*:../../meta-pkgs/boost
TOOL_DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4
TOOL_DEPENDS+=	libogg-[0-9]*:../../multimedia/libogg
TOOL_DEPENDS+=	libpcap-[0-9]*:../../net/libpcap
TOOL_DEPENDS+=	libsoup-[0-9]*:../../net/libsoup
TOOL_DEPENDS+=	poppler-[0-9]*:../../print/poppler
TOOL_DEPENDS+=	poppler-includes-[0-9]*:../../print/poppler-includes
TOOL_DEPENDS+=	cyrus-sasl-[0-9]*:../../security/cyrus-sasl
TOOL_DEPENDS+=	openssl-[0-9]*:../../security/openssl
TOOL_DEPENDS+=	tcp_wrappers-[0-9]*:../../security/tcp_wrappers
TOOL_DEPENDS+=	libnotify-[0-9]*:../../sysutils/libnotify
TOOL_DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3
TOOL_DEPENDS+=	motif-[0-9]*:../../x11/motif
TOOL_DEPENDS+=	tk-[0-9]*:../../x11/tk

#
# 4. Linux compat packages
#
TOOL_DEPENDS+=	suse>=13.1:../../meta-pkgs/suse131

#
# 5. Desktop infrastructure and support services
#
TOOL_DEPENDS+=	eawpatches-[0-9]*:../../audio/eawpatches
TOOL_DEPENDS+=	mpg123-pulse-[0-9]*:../../audio/mpg123-pulse
TOOL_DEPENDS+=	pulseaudio-[0-9]*:../../audio/pulseaudio
TOOL_DEPENDS+=	shared-mime-info-[0-9]*:../../databases/shared-mime-info
TOOL_DEPENDS+=	hicolor-icon-theme-[0-9]*:../../graphics/hicolor-icon-theme

#
# 6. Other very small packages
#
TOOL_DEPENDS+=	${LUA_PKGPREFIX}-stdlib-[0-9]*:../../devel/lua-stdlib

#
# Note that (unlike in bulk-small) we make no effort to list or track
# depends of the above. As long as the total size of this package
# remains roughly what we want, the exact list of depends doesn't
# matter too much.
#

# We are supposed to be a superset of bulk-small.
TOOL_DEPENDS+=	bulk-small-[0-9]*:../../meta-pkgs/bulk-small

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38
.include "../../lang/lua/luaversion.mk" # for LUA_PKGPREFIX
.include "../../lang/python/pyversion.mk" # for PYPKGPREFIX
.include "../../mk/bsd.pkg.mk"
