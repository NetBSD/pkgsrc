# $NetBSD: Makefile,v 1.71 2023/10/30 12:35:39 nia Exp $

DISTNAME=	bulk-large-20230915
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dholland@NetBSD.org
COMMENT=	Meta-package for a standard largish limited bulk build

META_PACKAGE=	yes

RESTRICTED=		Just for test build purpose
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

#
# Note: the primary purpose of this package is to build the most
# popular/useful packages out of the set of all packages in pkgsrc.
# On a fast build machine this whole meta-package should build in less
# than 24 hours, assuming that bulk-medium is already built.
#
# The guideline for adding stuff to this package is: if you had only
# a day or so to build 1/3 of pkgsrc, which 1/3 would be most useful
# to people using the resulting binary packages?
#
# Please discuss additions/removals on tech-pkg to avoid unnecessary
# churn.
#

.include "../../mk/bsd.prefs.mk"

#
# 0. By design bulk-large is supposed to be a superset of both
# bulk-medium and bulk-small. Depend on them rather than duplicating
# their listings. (Note that while bulk-medium is also supposed to be a
# superset of bulk-small, depend on both to avoid needing to think
# about that in detail.)
#
DEPENDS+=	bulk-medium-[0-9]*:../../meta-pkgs/bulk-medium
DEPENDS+=	bulk-small-[0-9]*:../../meta-pkgs/bulk-small

#
# 1. Packages used by a lot of other packages
#
DEPENDS+=	taglib-[0-9]*:../../audio/taglib
DEPENDS+=	gmp-[0-9]*:../../devel/gmp
DEPENDS+=	heirloom-libcommon-[0-9]*:../../devel/heirloom-libcommon
DEPENDS+=	libgetopt-[0-9]*:../../devel/libgetopt
DEPENDS+=	ocaml-[0-9]*:../../lang/ocaml
DEPENDS+=	gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base
DEPENDS+=	gstreamer1-[0-9]*:../../multimedia/gstreamer1
DEPENDS+=	libsoup-[0-9]*:../../net/libsoup
DEPENDS+=	dbus-[0-9]*:../../sysutils/dbus
DEPENDS+=	dbus-glib-[0-9]*:../../sysutils/dbus-glib
DEPENDS+=	aspell-[0-9]*:../../textproc/aspell
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	qt5-qtbase-[0-9]*:../../x11/qt5-qtbase
DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

#
# 2. Applications
#
DEPENDS+=	strawberry-[0-9]*:../../audio/strawberry
DEPENDS+=	musicpd-[0-9]*:../../audio/musicpd
DEPENDS+=	ncmpc-[0-9]*:../../audio/ncmpc
DEPENDS+=	mumble-[0-9]*:../../chat/mumble
DEPENDS+=	asterisk>=19:../../comms/asterisk19
DEPENDS+=	avr-gcc-[0-9]*:../../cross/avr-gcc
DEPENDS+=	avr-libc-[0-9]*:../../cross/avr-libc
DEPENDS+=	avr-gdb-[0-9]*:../../cross/avr-gdb
DEPENDS+=	mariadb-server>=10.6<10.7:../../databases/mariadb106-server
DEPENDS+=	mariadb-server>=10.11<10.12:../../databases/mariadb1011-server
DEPENDS+=	postgresql16-[0-9]*:../../databases/postgresql16
DEPENDS+=	emacs-[0-9]*:../../editors/emacs
DEPENDS+=	emacs-packages-[0-9]*:../../editors/emacs-packages
DEPENDS+=	p5-Padre-[0-9]*:../../editors/p5-Padre
DEPENDS+=	glusterfs-[0-9]*:../../filesystems/glusterfs
DEPENDS+=	tahoe-lafs-[0-9]*:../../filesystems/tahoe-lafs
DEPENDS+=	blender-[0-9]*:../../graphics/blender
DEPENDS+=	gimp-[0-9]*:../../graphics/gimp
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
DEPENDS+=	claws-mail-[0-9]*:../../mail/claws-mail
DEPENDS+=	${PHP_PKG_PREFIX}-roundcube-[0-9]*:../../mail/roundcube
DEPENDS+=	squirrelmail-[0-9]*:../../mail/squirrelmail
DEPENDS+=	thunderbird-[0-9]*:../../mail/thunderbird
DEPENDS+=	thunderbird-l10n-[0-9]*:../../mail/thunderbird-l10n
DEPENDS+=	R-[0-9]*:../../math/R
DEPENDS+=	octave-[0-9]*:../../math/octave
DEPENDS+=	zyGrib-[0-9]*:../../misc/zyGrib
DEPENDS+=	mpv-[0-9]*:../../multimedia/mpv
DEPENDS+=	qbittorrent-[0-9]*:../../net/qbittorrent
DEPENDS+=	wireshark-[0-9]*:../../net/wireshark
DEPENDS+=	cups-[0-9]*:../../print/cups
DEPENDS+=	lilypond-[0-9]*:../../print/lilypond
DEPENDS+=	mit-krb5-appl-[0-9]*:../../security/mit-krb5-appl
DEPENDS+=	mediawiki-[0-9]*:../../www/mediawiki
DEPENDS+=	${RUBY_PKGPREFIX}-rails61>=6.1.3:../../www/ruby-rails61
DEPENDS+=	${RUBY_PKGPREFIX}-rails70>=7.0.7:../../www/ruby-rails70

#
# 3. Libraries
#
DEPENDS+=	db5-[0-9]*:../../databases/db5
DEPENDS+=	heimdal-[0-9]*:../../security/heimdal
DEPENDS+=	mit-krb5-[0-9]*:../../security/mit-krb5

#
# 3A. Stuff that uses Rust that might otherwise be in bulk-medium or bulk-small
# (and used to be)
#
DEPENDS+=	gd-[0-9]*:../../graphics/gd
DEPENDS+=	${PYPKGPREFIX}-pspdfutils-[0-9]*:../../print/py-pspdfutils
DEPENDS+=	qemu-[0-9]*:../../emulators/qemu
DEPENDS+=	gnuplot-[0-9]*:../../graphics/gnuplot
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
.include "../../graphics/librsvg/available.mk"
.if ${LIBRSVG_TYPE} == "rust"
DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg
.else
DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg-c
.endif
DEPENDS+=	libsoup-[0-9]*:../../net/libsoup

#
# 4. TeX
#
DEPENDS+=	texlive-collection-fontsrecommended-[0-9]*:../../meta-pkgs/texlive-collection-fontsrecommended
DEPENDS+=	texlive-collection-fontsrecommended-doc-[0-9]*:../../meta-pkgs/texlive-collection-fontsrecommended-doc
DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic
DEPENDS+=	texlive-collection-basic-doc-[0-9]*:../../meta-pkgs/texlive-collection-basic-doc
DEPENDS+=	texlive-collection-plaingeneric-[0-9]*:../../meta-pkgs/texlive-collection-plaingeneric
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex
DEPENDS+=	texlive-collection-latex-doc-[0-9]*:../../meta-pkgs/texlive-collection-latex-doc

#
# 5. Desktops
#
DEPENDS+=	mate-[0-9]*:../../meta-pkgs/mate
DEPENDS+=	windowmaker-desktop-[0-9]*:../../meta-pkgs/windowmaker-desktop
DEPENDS+=	xfce4-[0-9]*:../../meta-pkgs/xfce4
DEPENDS+=	xfce4-extras-[0-9]*:../../meta-pkgs/xfce4-extras

#
# 6. NetBSD/pkgsrc developer tools
#
DEPENDS+=	netbsd-doc-[0-9]*:../../meta-pkgs/netbsd-doc
DEPENDS+=	netbsd-doc-print-[0-9]*:../../meta-pkgs/netbsd-doc-print
DEPENDS+=	netbsd-www-[0-9]*:../../meta-pkgs/netbsd-www
DEPENDS+=	pkg_developer-[0-9]*:../../meta-pkgs/pkg_developer
DEPENDS+=	pkgsrc-guide-tools-[0-9]*:../../meta-pkgs/pkgsrc-guide-tools

#
# 7. Complete X.org
#
.if ${X11_TYPE} != "native"
DEPENDS+=	modular-xorg-[0-9]*:../../meta-pkgs/modular-xorg
.endif

#
# Note that (unlike in bulk-small) we make no effort to list or track
# depends of the above. In many cases the packages listed above are
# intentionally chosen to bring in other things that we more or less
# want in here.
#

PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39
.include "../../lang/php/phpversion.mk" # for PHP_PKG_PREFIX
.include "../../lang/python/pyversion.mk" # for PYPKGPREFIX
.include "../../lang/ruby/rubyversion.mk" # for RUBY_PKGPREFIX
.include "../../mk/bsd.pkg.mk"
