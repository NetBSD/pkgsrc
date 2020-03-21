# $NetBSD: Makefile,v 1.46 2020/03/21 20:28:42 tnn Exp $

DISTNAME=	bulk-large-20200321
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

#
# 1. Packages used by a lot of other packages
#
BUILD_DEPENDS+=	taglib-[0-9]*:../../audio/taglib
BUILD_DEPENDS+=	gmp-[0-9]*:../../devel/gmp
BUILD_DEPENDS+=	heirloom-libcommon-[0-9]*:../../devel/heirloom-libcommon
BUILD_DEPENDS+=	libgetopt-[0-9]*:../../devel/libgetopt
BUILD_DEPENDS+=	ocaml-[0-9]*:../../lang/ocaml
BUILD_DEPENDS+=	gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base
BUILD_DEPENDS+=	gstreamer1-[0-9]*:../../multimedia/gstreamer1
BUILD_DEPENDS+=	libsoup-[0-9]*:../../net/libsoup
BUILD_DEPENDS+=	dbus-[0-9]*:../../sysutils/dbus
BUILD_DEPENDS+=	dbus-glib-[0-9]*:../../sysutils/dbus-glib
BUILD_DEPENDS+=	aspell-[0-9]*:../../textproc/aspell
BUILD_DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
BUILD_DEPENDS+=	qt5-qtbase-[0-9]*:../../x11/qt5-qtbase
BUILD_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

#
# 2. Applications
#
BUILD_DEPENDS+=	quassel-[0-9]*:../../chat/quassel
BUILD_DEPENDS+=	asterisk>=16:../../comms/asterisk16
BUILD_DEPENDS+=	avr-gcc-[0-9]*:../../cross/avr-gcc
BUILD_DEPENDS+=	avr-libc-[0-9]*:../../cross/avr-libc
BUILD_DEPENDS+=	avr-gdb-[0-9]*:../../cross/avr-gdb
BUILD_DEPENDS+=	mysql-client>=5.6<5.7:../../databases/mysql56-client
BUILD_DEPENDS+=	mysql-server>=5.6<5.7:../../databases/mysql56-server
BUILD_DEPENDS+=	mysql-client>=5.7:../../databases/mysql57-client
BUILD_DEPENDS+=	mysql-server>=5.7:../../databases/mysql57-server
BUILD_DEPENDS+=	postgresql95-[0-9]*:../../databases/postgresql95
BUILD_DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind
BUILD_DEPENDS+=	abiword-[0-9]*:../../editors/abiword
BUILD_DEPENDS+=	emacs25>=25<26:../../editors/emacs25
BUILD_DEPENDS+=	emacs-packages-[0-9]*:../../editors/emacs-packages
BUILD_DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
BUILD_DEPENDS+=	p5-Padre-[0-9]*:../../editors/p5-Padre
BUILD_DEPENDS+=	glusterfs-[0-9]*:../../filesystems/glusterfs
BUILD_DEPENDS+=	tahoe-lafs-[0-9]*:../../filesystems/tahoe-lafs
BUILD_DEPENDS+=	blender-[0-9]*:../../graphics/blender
BUILD_DEPENDS+=	gimp-[0-9]*:../../graphics/gimp
BUILD_DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
BUILD_DEPENDS+=	claws-mail-[0-9]*:../../mail/claws-mail
BUILD_DEPENDS+=	evolution-[0-9]*:../../mail/evolution
BUILD_DEPENDS+=	${PHP_PKG_PREFIX}-roundcube-[0-9]*:../../mail/roundcube
BUILD_DEPENDS+=	squirrelmail-[0-9]*:../../mail/squirrelmail
BUILD_DEPENDS+=	thunderbird-[0-9]*:../../mail/thunderbird
BUILD_DEPENDS+=	thunderbird-l10n-[0-9]*:../../mail/thunderbird-l10n
BUILD_DEPENDS+=	R-[0-9]*:../../math/R
BUILD_DEPENDS+=	octave-[0-9]*:../../math/octave
BUILD_DEPENDS+=	zyGrib-[0-9]*:../../misc/zyGrib
BUILD_DEPENDS+=	mpv-[0-9]*:../../multimedia/mpv
BUILD_DEPENDS+=	cups-[0-9]*:../../print/cups
BUILD_DEPENDS+=	atril-[0-9]*:../../print/atril
BUILD_DEPENDS+=	lilypond-[0-9]*:../../print/lilypond
BUILD_DEPENDS+=	mit-krb5-appl-[0-9]*:../../security/mit-krb5-appl
BUILD_DEPENDS+=	FlightCrew-[0-9]*:../../textproc/FlightCrew
BUILD_DEPENDS+=	clearsilver-[0-9]*:../../www/clearsilver
BUILD_DEPENDS+=	mediawiki-[0-9]*:../../www/mediawiki
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rails51>=5.1.6.1:../../www/ruby-rails51
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rails52>=5.2.2:../../www/ruby-rails52
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rails60>=6.0.2.2:../../www/ruby-rails60

#
# 3. Libraries
#
BUILD_DEPENDS+=	db5-[0-9]*:../../databases/db5
BUILD_DEPENDS+=	heimdal-[0-9]*:../../security/heimdal
BUILD_DEPENDS+=	mit-krb5-[0-9]*:../../security/mit-krb5

#
# 4. TeX
#
BUILD_DEPENDS+=	texlive-collection-fontsrecommended-[0-9]*:../../meta-pkgs/texlive-collection-fontsrecommended
BUILD_DEPENDS+=	texlive-collection-fontsrecommended-doc-[0-9]*:../../meta-pkgs/texlive-collection-fontsrecommended-doc
BUILD_DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic
BUILD_DEPENDS+=	texlive-collection-basic-doc-[0-9]*:../../meta-pkgs/texlive-collection-basic-doc
BUILD_DEPENDS+=	texlive-collection-plaingeneric-[0-9]*:../../meta-pkgs/texlive-collection-plaingeneric
BUILD_DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex
BUILD_DEPENDS+=	texlive-collection-latex-doc-[0-9]*:../../meta-pkgs/texlive-collection-latex-doc

#
# 5. Desktops
#
BUILD_DEPENDS+=	deforaos-desktop-[0-9]*:../../meta-pkgs/deforaos-desktop
BUILD_DEPENDS+=	gnustep-[0-9]*:../../meta-pkgs/gnustep
BUILD_DEPENDS+=	mate-[0-9]*:../../meta-pkgs/mate
BUILD_DEPENDS+=	windowmaker-desktop-[0-9]*:../../meta-pkgs/windowmaker-desktop
BUILD_DEPENDS+=	xfce4-[0-9]*:../../meta-pkgs/xfce4
BUILD_DEPENDS+=	xfce4-extras-[0-9]*:../../meta-pkgs/xfce4-extras
BUILD_DEPENDS+=	xview-[0-9]*:../../x11/xview

#
# 6. NetBSD/pkgsrc developer tools
#
BUILD_DEPENDS+=	netbsd-doc-[0-9]*:../../meta-pkgs/netbsd-doc
BUILD_DEPENDS+=	netbsd-doc-print-[0-9]*:../../meta-pkgs/netbsd-doc-print
BUILD_DEPENDS+=	netbsd-www-[0-9]*:../../meta-pkgs/netbsd-www
BUILD_DEPENDS+=	pkg_developer-[0-9]*:../../meta-pkgs/pkg_developer
BUILD_DEPENDS+=	pkgsrc-guide-tools-[0-9]*:../../meta-pkgs/pkgsrc-guide-tools

#
# 7. Complete X.org
#
BUILD_DEPENDS+=	modular-xorg-[0-9]*:../../meta-pkgs/modular-xorg


#
# Note that (unlike in bulk-small) we make no effort to list or track
# depends of the above. In many cases the packages listed above are
# intentionally chosen to bring in other things that we more or less
# want in here.
#

# We are supposed to be a superset of bulk-medium and bulk-small.
BUILD_DEPENDS+=	bulk-medium-[0-9]*:../../meta-pkgs/bulk-medium
BUILD_DEPENDS+=	bulk-small-[0-9]*:../../meta-pkgs/bulk-small

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/php/phpversion.mk" # for PHP_PKG_PREFIX
.include "../../lang/python/pyversion.mk" # for PYPKGPREFIX
.include "../../lang/ruby/rubyversion.mk" # for RUBY_PKGPREFIX
.include "../../mk/bsd.pkg.mk"
