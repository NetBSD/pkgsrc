# $NetBSD: Makefile,v 1.53 2023/06/06 12:41:53 riastradh Exp $

DISTNAME=	bulk-large-20211103
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
TOOL_DEPENDS+=	taglib-[0-9]*:../../audio/taglib
TOOL_DEPENDS+=	gmp-[0-9]*:../../devel/gmp
TOOL_DEPENDS+=	heirloom-libcommon-[0-9]*:../../devel/heirloom-libcommon
TOOL_DEPENDS+=	libgetopt-[0-9]*:../../devel/libgetopt
TOOL_DEPENDS+=	ocaml-[0-9]*:../../lang/ocaml
TOOL_DEPENDS+=	gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base
TOOL_DEPENDS+=	gstreamer1-[0-9]*:../../multimedia/gstreamer1
TOOL_DEPENDS+=	libsoup-[0-9]*:../../net/libsoup
TOOL_DEPENDS+=	dbus-[0-9]*:../../sysutils/dbus
TOOL_DEPENDS+=	dbus-glib-[0-9]*:../../sysutils/dbus-glib
TOOL_DEPENDS+=	aspell-[0-9]*:../../textproc/aspell
TOOL_DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
TOOL_DEPENDS+=	qt5-qtbase-[0-9]*:../../x11/qt5-qtbase
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

#
# 2. Applications
#
TOOL_DEPENDS+=	quassel-[0-9]*:../../chat/quassel
TOOL_DEPENDS+=	asterisk>=16:../../comms/asterisk16
TOOL_DEPENDS+=	avr-gcc-[0-9]*:../../cross/avr-gcc
TOOL_DEPENDS+=	avr-libc-[0-9]*:../../cross/avr-libc
TOOL_DEPENDS+=	avr-gdb-[0-9]*:../../cross/avr-gdb
TOOL_DEPENDS+=	mariadb-server>=10.5<10.6:../../databases/mariadb105-server
TOOL_DEPENDS+=	mariadb-server>=10.6<10.7:../../databases/mariadb106-server
TOOL_DEPENDS+=	postgresql13-[0-9]*:../../databases/postgresql13
TOOL_DEPENDS+=	abiword-[0-9]*:../../editors/abiword
TOOL_DEPENDS+=	emacs26>=26<27:../../editors/emacs26
TOOL_DEPENDS+=	emacs-packages-[0-9]*:../../editors/emacs-packages
TOOL_DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
TOOL_DEPENDS+=	p5-Padre-[0-9]*:../../editors/p5-Padre
TOOL_DEPENDS+=	glusterfs-[0-9]*:../../filesystems/glusterfs
TOOL_DEPENDS+=	tahoe-lafs-[0-9]*:../../filesystems/tahoe-lafs
TOOL_DEPENDS+=	blender-[0-9]*:../../graphics/blender
TOOL_DEPENDS+=	gimp-[0-9]*:../../graphics/gimp
TOOL_DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
TOOL_DEPENDS+=	claws-mail-[0-9]*:../../mail/claws-mail
TOOL_DEPENDS+=	evolution-[0-9]*:../../mail/evolution
TOOL_DEPENDS+=	${PHP_PKG_PREFIX}-roundcube-[0-9]*:../../mail/roundcube
TOOL_DEPENDS+=	squirrelmail-[0-9]*:../../mail/squirrelmail
TOOL_DEPENDS+=	thunderbird-[0-9]*:../../mail/thunderbird
TOOL_DEPENDS+=	thunderbird-l10n-[0-9]*:../../mail/thunderbird-l10n
TOOL_DEPENDS+=	R-[0-9]*:../../math/R
TOOL_DEPENDS+=	octave-[0-9]*:../../math/octave
TOOL_DEPENDS+=	zyGrib-[0-9]*:../../misc/zyGrib
TOOL_DEPENDS+=	mpv-[0-9]*:../../multimedia/mpv
TOOL_DEPENDS+=	cups-[0-9]*:../../print/cups
TOOL_DEPENDS+=	atril-[0-9]*:../../print/atril
TOOL_DEPENDS+=	lilypond-[0-9]*:../../print/lilypond
TOOL_DEPENDS+=	mit-krb5-appl-[0-9]*:../../security/mit-krb5-appl
TOOL_DEPENDS+=	FlightCrew-[0-9]*:../../textproc/FlightCrew
TOOL_DEPENDS+=	clearsilver-[0-9]*:../../www/clearsilver
TOOL_DEPENDS+=	mediawiki-[0-9]*:../../www/mediawiki
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-rails52>=5.2.4.5:../../www/ruby-rails52
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-rails60>=6.0.3.5:../../www/ruby-rails60
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-rails61>=6.1.3:../../www/ruby-rails61

#
# 3. Libraries
#
TOOL_DEPENDS+=	db5-[0-9]*:../../databases/db5
TOOL_DEPENDS+=	heimdal-[0-9]*:../../security/heimdal
TOOL_DEPENDS+=	mit-krb5-[0-9]*:../../security/mit-krb5

#
# 4. TeX
#
TOOL_DEPENDS+=	texlive-collection-fontsrecommended-[0-9]*:../../meta-pkgs/texlive-collection-fontsrecommended
TOOL_DEPENDS+=	texlive-collection-fontsrecommended-doc-[0-9]*:../../meta-pkgs/texlive-collection-fontsrecommended-doc
TOOL_DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic
TOOL_DEPENDS+=	texlive-collection-basic-doc-[0-9]*:../../meta-pkgs/texlive-collection-basic-doc
TOOL_DEPENDS+=	texlive-collection-plaingeneric-[0-9]*:../../meta-pkgs/texlive-collection-plaingeneric
TOOL_DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex
TOOL_DEPENDS+=	texlive-collection-latex-doc-[0-9]*:../../meta-pkgs/texlive-collection-latex-doc

#
# 5. Desktops
#
TOOL_DEPENDS+=	deforaos-desktop-[0-9]*:../../meta-pkgs/deforaos-desktop
TOOL_DEPENDS+=	gnustep-[0-9]*:../../meta-pkgs/gnustep
TOOL_DEPENDS+=	mate-[0-9]*:../../meta-pkgs/mate
TOOL_DEPENDS+=	windowmaker-desktop-[0-9]*:../../meta-pkgs/windowmaker-desktop
TOOL_DEPENDS+=	xfce4-[0-9]*:../../meta-pkgs/xfce4
TOOL_DEPENDS+=	xfce4-extras-[0-9]*:../../meta-pkgs/xfce4-extras
TOOL_DEPENDS+=	xview-[0-9]*:../../x11/xview

#
# 6. NetBSD/pkgsrc developer tools
#
TOOL_DEPENDS+=	netbsd-doc-[0-9]*:../../meta-pkgs/netbsd-doc
TOOL_DEPENDS+=	netbsd-doc-print-[0-9]*:../../meta-pkgs/netbsd-doc-print
TOOL_DEPENDS+=	netbsd-www-[0-9]*:../../meta-pkgs/netbsd-www
TOOL_DEPENDS+=	pkg_developer-[0-9]*:../../meta-pkgs/pkg_developer
TOOL_DEPENDS+=	pkgsrc-guide-tools-[0-9]*:../../meta-pkgs/pkgsrc-guide-tools

#
# 7. Complete X.org
#
TOOL_DEPENDS+=	modular-xorg-[0-9]*:../../meta-pkgs/modular-xorg


#
# Note that (unlike in bulk-small) we make no effort to list or track
# depends of the above. In many cases the packages listed above are
# intentionally chosen to bring in other things that we more or less
# want in here.
#

# We are supposed to be a superset of bulk-medium and bulk-small.
TOOL_DEPENDS+=	bulk-medium-[0-9]*:../../meta-pkgs/bulk-medium
TOOL_DEPENDS+=	bulk-small-[0-9]*:../../meta-pkgs/bulk-small

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/php/phpversion.mk" # for PHP_PKG_PREFIX
.include "../../lang/python/pyversion.mk" # for PYPKGPREFIX
.include "../../lang/ruby/rubyversion.mk" # for RUBY_PKGPREFIX
.include "../../mk/bsd.pkg.mk"
