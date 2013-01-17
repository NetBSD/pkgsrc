# $NetBSD: Makefile,v 1.1 2013/01/17 03:51:05 dholland Exp $

DISTNAME=	bulk-medium-20130113
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dholland@NetBSD.org
COMMENT=	Meta-package for a standard medium-sized limited bulk build

META_PACKAGE=	yes

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
DEPENDS+=	cdparanoia-[0-9]*:../../audio/cdparanoia
DEPENDS+=	flac-[0-9]*:../../audio/flac
DEPENDS+=	flac123-[0-9]*:../../audio/flac123
DEPENDS+=	lame-[0-9]*:../../audio/lame
DEPENDS+=	mpg123-[0-9]*:../../audio/mpg123
DEPENDS+=	mpg321-[0-9]*:../../audio/mpg321
DEPENDS+=	sox-[0-9]*:../../audio/sox
DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools
DEPENDS+=	jabberd-[0-9]*:../../chat/jabberd
DEPENDS+=	jabberd2-[0-9]*:../../chat/jabberd2
DEPENDS+=	sirc-[0-9]*:../../chat/sirc
DEPENDS+=	xchat-[0-9]*:../../chat/xchat
DEPENDS+=	xchat-perl-[0-9]*:../../chat/xchat-perl
DEPENDS+=	xchat-python-[0-9]*:../../chat/xchat-python
DEPENDS+=	fribidi-[0-9]*:../../converters/fribidi
DEPENDS+=	mysql51-client-[0-9]*:../../databases/mysql51-client
DEPENDS+=	mysql55-client-[0-9]*:../../databases/mysql55-client
DEPENDS+=	openldap-client-[0-9]*:../../databases/openldap-client
DEPENDS+=	postgresql84-client-[0-9]*:../../databases/postgresql84-client
DEPENDS+=	postgresql91-client-[0-9]*:../../databases/postgresql91-client
DEPENDS+=	scmgit-[0-9]*:../../devel/scmgit
DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base
DEPENDS+=	scmgit-docs-[0-9]*:../../devel/scmgit-docs
DEPENDS+=	mercurial-[0-9]*:../../devel/mercurial
DEPENDS+=	emacs>=23<24:../../editors/emacs
DEPENDS+=	nvi-[0-9]*:../../editors/nvi
DEPENDS+=	vim-gtk2-[0-9]*:../../editors/vim-gtk2
DEPENDS+=	xemacs-[0-9]*:../../editors/xemacs
DEPENDS+=	qemu-[0-9]*:../../emulators/qemu
DEPENDS+=	simh-[0-9]*:../../emulators/simh
DEPENDS+=	tme-[0-9]*:../../emulators/tme
DEPENDS+=	wine-[0-9]*:../../emulators/wine
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot
DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
DEPENDS+=	py-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	py-matplotlib-gtk2-[0-9]*:../../graphics/py-matplotlib-gtk2
DEPENDS+=	py-matplotlib-tk-[0-9]*:../../graphics/py-matplotlib-tk
DEPENDS+=	gawk-[0-9]*:../../lang/gawk
DEPENDS+=	php>=5.3<5.4:../../lang/php53
DEPENDS+=	php>=5.4<5.5:../../lang/php54
DEPENDS+=	ruby18-base-[0-9]*:../../lang/ruby18-base
DEPENDS+=	ruby193-base-[0-9]*:../../lang/ruby193-base
DEPENDS+=	sun-jdk6-[0-9]*:../../lang/sun-jdk6
DEPENDS+=	sun-jre6-[0-9]*:../../lang/sun-jre6
DEPENDS+=	openjdk7-[0-9]*:../../lang/openjdk7
DEPENDS+=	openjdk7-bin-[0-9]*:../../lang/openjdk7-bin
DEPENDS+=	python26-[0-9]*:../../lang/python26
DEPENDS+=	python31-[0-9]*:../../lang/python31
DEPENDS+=	python32-[0-9]*:../../lang/python32
DEPENDS+=	python33-[0-9]*:../../lang/python33
DEPENDS+=	tcl-[0-9]*:../../lang/tcl
DEPENDS+=	fetchmail-[0-9]*:../../mail/fetchmail
DEPENDS+=	imap-uw-[0-9]*:../../mail/imap-uw
DEPENDS+=	mailman-[0-9]*:../../mail/mailman
DEPENDS+=	mhonarc-[0-9]*:../../mail/mhonarc
DEPENDS+=	mutt-[0-9]*:../../mail/mutt
DEPENDS+=	re-alpine-[0-9]*:../../mail/re-alpine
DEPENDS+=	spamassassin-[0-9]*:../../mail/spamassassin
DEPENDS+=	bind96-[0-9]*:../../net/bind96
DEPENDS+=	bind97-[0-9]*:../../net/bind97
DEPENDS+=	bind98-[0-9]*:../../net/bind98
DEPENDS+=	bind99-[0-9]*:../../net/bind99
DEPENDS+=	clive-[0-9]*:../../net/clive
DEPENDS+=	nmap-[0-9]*:../../net/nmap
DEPENDS+=	samba35-[0-9]*:../../net/samba35
DEPENDS+=	wpa_supplicant-[0-9]*:../../net/wpa_supplicant
DEPENDS+=	xymon-[0-9]*:../../net/xymon
DEPENDS+=	xymonclient-[0-9]*:../../net/xymonclient
DEPENDS+=	youtube-dl-[0-9]*:../../net/youtube-dl
DEPENDS+=	lintpkgsrc-[0-9]*:../../pkgtools/lintpkgsrc
DEPENDS+=	pkglint-[0-9]*:../../pkgtools/pkglint
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils
DEPENDS+=	xpdf-[0-9]*:../../print/xpdf
DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
DEPENDS+=	desktop-file-utils-[0-9]*:../../sysutils/desktop-file-utils
DEPENDS+=	xe-guest-utilities-[0-9]*:../../sysutils/xe-guest-utilities
DEPENDS+=	xenkernel41-[0-9]*:../../sysutils/xenkernel41
DEPENDS+=	xentools41-[0-9]*:../../sysutils/xentools41
DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base
DEPENDS+=	firefox10-[0-9]*:../../www/firefox10
DEPENDS+=	seamonkey-[0-9]*:../../www/seamonkey
DEPENDS+=	xlockmore-[0-9]*:../../x11/xlockmore

#
# 2. Archivers and build tools
#
DEPENDS+=	pigz-[0-9]*:../../archivers/pigz
DEPENDS+=	cmake-[0-9]*:../../devel/cmake
DEPENDS+=	imake-[0-9]*:../../devel/imake
DEPENDS+=	nasm-[0-9]*:../../devel/nasm
DEPENDS+=	yasm-[0-9]*:../../devel/yasm
DEPENDS+=	icon-naming-utils-[0-9]*:../../graphics/icon-naming-utils

#
# 3. Commonly used libraries
#
DEPENDS+=	SDL_mixer-[0-9]*:../../audio/SDL_mixer
DEPENDS+=	libmad-[0-9]*:../../audio/libmad
DEPENDS+=	libvorbis-[0-9]*:../../audio/libvorbis
DEPENDS+=	gdbm-[0-9]*:../../databases/gdbm
DEPENDS+=	p5-BDB-[0-9]*:../../databases/p5-BDB
DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	py-bsddb3-[0-9]*:../../databases/py-bsddb3
DEPENDS+=	py-gdbm-[0-9]*:../../databases/py-gdbm
DEPENDS+=	py-postgresql-[0-9]*:../../databases/py-postgresql
DEPENDS+=	py-psycopg2-[0-9]*:../../databases/py-psycopg2
DEPENDS+=	py-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	SDL-[0-9]*:../../devel/SDL
DEPENDS+=	atk-[0-9]*:../../devel/atk
DEPENDS+=	boehm-gc-[0-9]*:../../devel/boehm-gc
DEPENDS+=	glib2-[0-9]*:../../devel/glib2
DEPENDS+=	libelf-[0-9]*:../../devel/libelf
DEPENDS+=	libf2c-[0-9]*:../../devel/libf2c
DEPENDS+=	libglade-[0-9]*:../../devel/libglade
DEPENDS+=	libidn-[0-9]*:../../devel/libidn
DEPENDS+=	libltdl-[0-9]*:../../devel/libltdl
DEPENDS+=	libusb-[0-9]*:../../devel/libusb
DEPENDS+=	ncurses-[0-9]*:../../devel/ncurses
DEPENDS+=	ncursesw-[0-9]*:../../devel/ncursesw
DEPENDS+=	pango-[0-9]*:../../devel/pango
DEPENDS+=	pangox-compat-[0-9]*:../../devel/pangox-compat
DEPENDS+=	pcre-[0-9]*:../../devel/pcre
DEPENDS+=	popt-[0-9]*:../../devel/popt
DEPENDS+=	fuse-[0-9]*:../../filesystems/fuse
DEPENDS+=	perfuse-[0-9]*:../../filesystems/perfuse
DEPENDS+=	SDL_image-[0-9]*:../../graphics/SDL_image
DEPENDS+=	cairo-[0-9]*:../../graphics/cairo
DEPENDS+=	gdk-pixbuf2-[0-9]*:../../graphics/gdk-pixbuf2
DEPENDS+=	glew-[0-9]*:../../graphics/glew
DEPENDS+=	jasper-[0-9]*:../../graphics/jasper
DEPENDS+=	lcms-[0-9]*:../../graphics/lcms
DEPENDS+=	lcms2-[0-9]*:../../graphics/lcms2
DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg
DEPENDS+=	blas-[0-9]*:../../math/blas
DEPENDS+=	lapack-[0-9]*:../../math/lapack
DEPENDS+=	boost-[0-9]*:../../meta-pkgs/boost
DEPENDS+=	ffmpeg-[0-9]*:../../multimedia/ffmpeg
DEPENDS+=	ffmpeg010-[0-9]*:../../multimedia/ffmpeg010
DEPENDS+=	libogg-[0-9]*:../../multimedia/libogg
DEPENDS+=	libpcap-[0-9]*:../../net/libpcap
DEPENDS+=	libsoup24-[0-9]*:../../net/libsoup24
DEPENDS+=	poppler-[0-9]*:../../print/poppler
DEPENDS+=	poppler-includes-[0-9]*:../../print/poppler-includes
DEPENDS+=	cyrus-sasl-[0-9]*:../../security/cyrus-sasl
DEPENDS+=	openssl-[0-9]*:../../security/openssl
DEPENDS+=	tcp_wrappers-[0-9]*:../../security/tcp_wrappers
DEPENDS+=	gnome-vfs-[0-9]*:../../sysutils/gnome-vfs
DEPENDS+=	libnotify-[0-9]*:../../sysutils/libnotify
DEPENDS+=	gtk2+-[0-9]*:../../x11/gtk2
DEPENDS+=	motif-[0-9]*:../../x11/motif
DEPENDS+=	tk-[0-9]*:../../x11/tk

#
# 4. Linux compat packages
#
DEPENDS+=	suse121-[0-9]*:../../meta-pkgs/suse121

#
# 5. Desktop infrastructure and support services
#
DEPENDS+=	eawpatches-[0-9]*:../../audio/eawpatches
DEPENDS+=	mpg123-pulse-[0-9]*:../../audio/mpg123-pulse
DEPENDS+=	pulseaudio-[0-9]*:../../audio/pulseaudio
DEPENDS+=	shared-mime-info-[0-9]*:../../databases/shared-mime-info
DEPENDS+=	hicolor-icon-theme-[0-9]*:../../graphics/hicolor-icon-theme

#
# 6. Other very small packages
#
DEPENDS+=	lua-stdlib-[0-9]*:../../devel/lua-stdlib
DEPENDS+=	lua-stdlib-doc-[0-9]*:../../devel/lua-stdlib-doc

#
# Note that (unlike in bulk-small) we make no effort to list or track
# depends of the above. As long as the total size of this package
# remains roughly what we want, the exact list of depends doesn't
# matter too much.
#

# We are supposed to be a superset of bulk-small.
DEPENDS+=	bulk-small-[0-9]*:../../meta-pkgs/bulk-small

.include "../../mk/bsd.pkg.mk"
