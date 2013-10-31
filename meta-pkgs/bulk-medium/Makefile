# $NetBSD: Makefile,v 1.12 2013/10/31 23:38:30 dholland Exp $

DISTNAME=	bulk-medium-20131031
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
BUILD_DEPENDS+=	cdparanoia-[0-9]*:../../audio/cdparanoia
BUILD_DEPENDS+=	flac-[0-9]*:../../audio/flac
BUILD_DEPENDS+=	flac123-[0-9]*:../../audio/flac123
BUILD_DEPENDS+=	lame-[0-9]*:../../audio/lame
BUILD_DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123
BUILD_DEPENDS+=	mpg321-[0-9]*:../../audio/mpg321
BUILD_DEPENDS+=	sox-[0-9]*:../../audio/sox
BUILD_DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools
BUILD_DEPENDS+=	jabberd>=1<2:../../chat/jabberd
BUILD_DEPENDS+=	jabberd>=2:../../chat/jabberd2
BUILD_DEPENDS+=	sirc-[0-9]*:../../chat/sirc
BUILD_DEPENDS+=	xchat-[0-9]*:../../chat/xchat
BUILD_DEPENDS+=	xchat-perl-[0-9]*:../../chat/xchat-perl
BUILD_DEPENDS+=	xchat-python-[0-9]*:../../chat/xchat-python
BUILD_DEPENDS+=	fribidi-[0-9]*:../../converters/fribidi
BUILD_DEPENDS+=	mysql-client>=5.1<5.5:../../databases/mysql51-client
BUILD_DEPENDS+=	mysql-client>=5.5:../../databases/mysql55-client
BUILD_DEPENDS+=	openldap-client-[0-9]*:../../databases/openldap-client
BUILD_DEPENDS+=	postgresql84-client-[0-9]*:../../databases/postgresql84-client
BUILD_DEPENDS+=	postgresql91-client-[0-9]*:../../databases/postgresql91-client
BUILD_DEPENDS+=	git-[0-9]*:../../devel/git
BUILD_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
BUILD_DEPENDS+=	git-docs-[0-9]*:../../devel/git-docs
BUILD_DEPENDS+=	mercurial-[0-9]*:../../devel/mercurial
BUILD_DEPENDS+=	emacs24>=24<25:../../editors/emacs24
BUILD_DEPENDS+=	emacs-packages-[0-9]*:../../editors/emacs-packages
BUILD_DEPENDS+=	nvi-[0-9]*:../../editors/nvi
BUILD_DEPENDS+=	vim-gtk2-[0-9]*:../../editors/vim-gtk2
BUILD_DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
BUILD_DEPENDS+=	qemu-[0-9]*:../../emulators/qemu
BUILD_DEPENDS+=	simh-[0-9]*:../../emulators/simh
BUILD_DEPENDS+=	tme-[0-9]*:../../emulators/tme
BUILD_DEPENDS+=	wine-[0-9]*:../../emulators/wine
BUILD_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
BUILD_DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot
BUILD_DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
BUILD_DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
BUILD_DEPENDS+=	${PYPKGPREFIX}-matplotlib-gtk-[0-9]*:../../graphics/py-matplotlib-gtk2
BUILD_DEPENDS+=	${PYPKGPREFIX}-matplotlib-tk-[0-9]*:../../graphics/py-matplotlib-tk
BUILD_DEPENDS+=	gawk-[0-9]*:../../lang/gawk
BUILD_DEPENDS+=	php>=5.3<5.4:../../lang/php53
BUILD_DEPENDS+=	php>=5.4<5.5:../../lang/php54
BUILD_DEPENDS+=	ruby18-base-[0-9]*:../../lang/ruby18-base
BUILD_DEPENDS+=	ruby193-base-[0-9]*:../../lang/ruby193-base
BUILD_DEPENDS+=	sun-jdk6-[0-9]*:../../lang/sun-jdk6
BUILD_DEPENDS+=	sun-jre6-[0-9]*:../../lang/sun-jre6
BUILD_DEPENDS+=	openjdk7-[0-9]*:../../lang/openjdk7
BUILD_DEPENDS+=	openjdk7-bin-[0-9]*:../../lang/openjdk7-bin
BUILD_DEPENDS+=	python26-[0-9]*:../../lang/python26
BUILD_DEPENDS+=	python32-[0-9]*:../../lang/python32
BUILD_DEPENDS+=	python33-[0-9]*:../../lang/python33
BUILD_DEPENDS+=	tcl-[0-9]*:../../lang/tcl
BUILD_DEPENDS+=	fetchmail-[0-9]*:../../mail/fetchmail
BUILD_DEPENDS+=	imap-uw-[0-9]*:../../mail/imap-uw
BUILD_DEPENDS+=	mailman-[0-9]*:../../mail/mailman
BUILD_DEPENDS+=	mhonarc-[0-9]*:../../mail/mhonarc
BUILD_DEPENDS+=	mutt-[0-9]*:../../mail/mutt
BUILD_DEPENDS+=	re-alpine-[0-9]*:../../mail/re-alpine
BUILD_DEPENDS+=	spamassassin-[0-9]*:../../mail/spamassassin
BUILD_DEPENDS+=	bind>=9.6<9.7:../../net/bind96
BUILD_DEPENDS+=	bind>=9.8<9.9:../../net/bind98
BUILD_DEPENDS+=	bind>=9.9<9.10:../../net/bind99
BUILD_DEPENDS+=	clive-[0-9]*:../../net/clive
BUILD_DEPENDS+=	nmap-[0-9]*:../../net/nmap
BUILD_DEPENDS+=	samba>=3.5<3.6:../../net/samba35
BUILD_DEPENDS+=	samba>=3.6:../../net/samba
BUILD_DEPENDS+=	wpa_supplicant-[0-9]*:../../net/wpa_supplicant
BUILD_DEPENDS+=	xymon-[0-9]*:../../net/xymon
BUILD_DEPENDS+=	xymonclient-[0-9]*:../../net/xymonclient
BUILD_DEPENDS+=	youtube-dl-[0-9]*:../../net/youtube-dl
BUILD_DEPENDS+=	lintpkgsrc-[0-9]*:../../pkgtools/lintpkgsrc
BUILD_DEPENDS+=	pkglint-[0-9]*:../../pkgtools/pkglint
BUILD_DEPENDS+=	ghostscript-agpl-[0-9]*:../../print/ghostscript-agpl
BUILD_DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
BUILD_DEPENDS+=	xpdf-[0-9]*:../../print/xpdf
BUILD_DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
BUILD_DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
BUILD_DEPENDS+=	desktop-file-utils-[0-9]*:../../sysutils/desktop-file-utils
BUILD_DEPENDS+=	xe-guest-utilities-[0-9]*:../../sysutils/xe-guest-utilities
BUILD_DEPENDS+=	xenkernel41-[0-9]*:../../sysutils/xenkernel41
BUILD_DEPENDS+=	xentools41-[0-9]*:../../sysutils/xentools41
BUILD_DEPENDS+=	ispell-[0-9]*:../../textproc/ispell
BUILD_DEPENDS+=	firefox10-[0-9]*:../../www/firefox10
BUILD_DEPENDS+=	seamonkey-[0-9]*:../../www/seamonkey
BUILD_DEPENDS+=	xlockmore-[0-9]*:../../x11/xlockmore

#
# 2. Archivers and build tools
#
BUILD_DEPENDS+=	pigz-[0-9]*:../../archivers/pigz
BUILD_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
BUILD_DEPENDS+=	imake-[0-9]*:../../devel/imake
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
BUILD_DEPENDS+=	icon-naming-utils-[0-9]*:../../graphics/icon-naming-utils

#
# 3. Commonly used libraries
#
BUILD_DEPENDS+=	SDL_mixer-[0-9]*:../../audio/SDL_mixer
BUILD_DEPENDS+=	libmad-[0-9]*:../../audio/libmad
BUILD_DEPENDS+=	libvorbis-[0-9]*:../../audio/libvorbis
BUILD_DEPENDS+=	gdbm-[0-9]*:../../databases/gdbm
BUILD_DEPENDS+=	p5-BDB-[0-9]*:../../databases/p5-BDB
BUILD_DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB
BUILD_DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
BUILD_DEPENDS+=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
BUILD_DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
BUILD_DEPENDS+=	${PYPKGPREFIX}-bsddb3-[0-9]*:../../databases/py-bsddb3
BUILD_DEPENDS+=	${PYPKGPREFIX}-gdbm-[0-9]*:../../databases/py-gdbm
BUILD_DEPENDS+=	${PYPKGPREFIX}-postgresql-[0-9]*:../../databases/py-postgresql
BUILD_DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
BUILD_DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
BUILD_DEPENDS+=	SDL-[0-9]*:../../devel/SDL
BUILD_DEPENDS+=	atk-[0-9]*:../../devel/atk
BUILD_DEPENDS+=	boehm-gc-[0-9]*:../../devel/boehm-gc
BUILD_DEPENDS+=	glib2-[0-9]*:../../devel/glib2
BUILD_DEPENDS+=	libelf-[0-9]*:../../devel/libelf
BUILD_DEPENDS+=	libf2c-[0-9]*:../../devel/libf2c
BUILD_DEPENDS+=	libglade-[0-9]*:../../devel/libglade
BUILD_DEPENDS+=	libidn-[0-9]*:../../devel/libidn
BUILD_DEPENDS+=	libltdl-[0-9]*:../../devel/libltdl
BUILD_DEPENDS+=	libusb-[0-9]*:../../devel/libusb
BUILD_DEPENDS+=	ncurses-[0-9]*:../../devel/ncurses
BUILD_DEPENDS+=	ncursesw-[0-9]*:../../devel/ncursesw
BUILD_DEPENDS+=	pango-[0-9]*:../../devel/pango
BUILD_DEPENDS+=	pangox-compat-[0-9]*:../../devel/pangox-compat
BUILD_DEPENDS+=	pcre-[0-9]*:../../devel/pcre
BUILD_DEPENDS+=	popt-[0-9]*:../../devel/popt
BUILD_DEPENDS+=	fuse-[0-9]*:../../filesystems/fuse
BUILD_DEPENDS+=	perfuse-[0-9]*:../../filesystems/perfuse
BUILD_DEPENDS+=	SDL_image-[0-9]*:../../graphics/SDL_image
BUILD_DEPENDS+=	cairo-[0-9]*:../../graphics/cairo
BUILD_DEPENDS+=	gdk-pixbuf2-[0-9]*:../../graphics/gdk-pixbuf2
BUILD_DEPENDS+=	glew-[0-9]*:../../graphics/glew
BUILD_DEPENDS+=	jasper-[0-9]*:../../graphics/jasper
BUILD_DEPENDS+=	lcms-[0-9]*:../../graphics/lcms
BUILD_DEPENDS+=	lcms2-[0-9]*:../../graphics/lcms2
BUILD_DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg
BUILD_DEPENDS+=	blas-[0-9]*:../../math/blas
BUILD_DEPENDS+=	lapack-[0-9]*:../../math/lapack
BUILD_DEPENDS+=	boost-[0-9]*:../../meta-pkgs/boost
BUILD_DEPENDS+=	ffmpeg-[0-9]*:../../multimedia/ffmpeg
BUILD_DEPENDS+=	ffmpeg010-[0-9]*:../../multimedia/ffmpeg010
BUILD_DEPENDS+=	libogg-[0-9]*:../../multimedia/libogg
BUILD_DEPENDS+=	libpcap-[0-9]*:../../net/libpcap
BUILD_DEPENDS+=	libsoup24-[0-9]*:../../net/libsoup24
BUILD_DEPENDS+=	poppler-[0-9]*:../../print/poppler
BUILD_DEPENDS+=	poppler-includes-[0-9]*:../../print/poppler-includes
BUILD_DEPENDS+=	cyrus-sasl-[0-9]*:../../security/cyrus-sasl
BUILD_DEPENDS+=	openssl-[0-9]*:../../security/openssl
BUILD_DEPENDS+=	tcp_wrappers-[0-9]*:../../security/tcp_wrappers
BUILD_DEPENDS+=	gnome-vfs-[0-9]*:../../sysutils/gnome-vfs
BUILD_DEPENDS+=	libnotify-[0-9]*:../../sysutils/libnotify
BUILD_DEPENDS+=	gtk2+-[0-9]*:../../x11/gtk2
BUILD_DEPENDS+=	motif-[0-9]*:../../x11/motif
BUILD_DEPENDS+=	tk-[0-9]*:../../x11/tk

#
# 4. Linux compat packages
#
BUILD_DEPENDS+=	suse>=12.1:../../meta-pkgs/suse121

#
# 5. Desktop infrastructure and support services
#
BUILD_DEPENDS+=	eawpatches-[0-9]*:../../audio/eawpatches
BUILD_DEPENDS+=	mpg123-pulse-[0-9]*:../../audio/mpg123-pulse
BUILD_DEPENDS+=	pulseaudio-[0-9]*:../../audio/pulseaudio
BUILD_DEPENDS+=	shared-mime-info-[0-9]*:../../databases/shared-mime-info
BUILD_DEPENDS+=	hicolor-icon-theme-[0-9]*:../../graphics/hicolor-icon-theme

#
# 6. Other very small packages
#
BUILD_DEPENDS+=	${LUA_PKGPREFIX}-stdlib-[0-9]*:../../devel/lua-stdlib
BUILD_DEPENDS+=	${LUA_PKGPREFIX}-stdlib-doc-[0-9]*:../../devel/lua-stdlib-doc

#
# Note that (unlike in bulk-small) we make no effort to list or track
# depends of the above. As long as the total size of this package
# remains roughly what we want, the exact list of depends doesn't
# matter too much.
#

# We are supposed to be a superset of bulk-small.
BUILD_DEPENDS+=	bulk-small-[0-9]*:../../meta-pkgs/bulk-small

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/lua/luaversion.mk" # for LUA_PKGPREFIX
.include "../../lang/python/pyversion.mk" # for PYPKGPREFIX
.include "../../mk/bsd.pkg.mk"
