# $NetBSD: Makefile,v 1.1 2013/01/17 03:51:05 dholland Exp $

DISTNAME=	bulk-large-20130113
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dholland@NetBSD.org
COMMENT=	Meta-package for a standard largish limited bulk build

META_PACKAGE=	yes

#
# Note: the primary purpose of this package is to build the most
# popular/useful packages out of the set of all packages in pkgsrc.
# On a fast build machine this whole meta-package should build in less
# than 24 hous, assuming that bulk-medium is already built.
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
DEPENDS+=	taglib-[0-9]*:../../audio/taglib
DEPENDS+=	GConf-[0-9]*:../../devel/GConf
DEPENDS+=	gmp-[0-9]*:../../devel/gmp
DEPENDS+=	heirloom-libcommon-[0-9]*:../../devel/heirloom-libcommon
DEPENDS+=	libgetopt-[0-9]*:../../devel/libgetopt
DEPENDS+=	libgnome-[0-9]*:../../devel/libgnome
DEPENDS+=	libgnomeui-[0-9]*:../../devel/libgnomeui
DEPENDS+=	ocaml-[0-9]*:../../lang/ocaml
DEPENDS+=	gst-plugins0.10-base-[0-9]*:../../multimedia/gst-plugins0.10-base
DEPENDS+=	gstreamer0.10-[0-9]*:../../multimedia/gstreamer0.10
DEPENDS+=	libsoup24-[0-9]*:../../net/libsoup24
DEPENDS+=	dbus-[0-9]*:../../sysutils/dbus
DEPENDS+=	dbus-glib-[0-9]*:../../sysutils/dbus-glib
DEPENDS+=	aspell-[0-9]*:../../textproc/aspell
DEPENDS+=	gnome-doc-utils-[0-9]*:../../textproc/gnome-doc-utils
DEPENDS+=	kdebase3-[0-9]*:../../x11/kdebase3
DEPENDS+=	kdelibs3-[0-9]*:../../x11/kdelibs3
DEPENDS+=	kdelibs4-[0-9]*:../../x11/kdelibs4
DEPENDS+=	py-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	qt3-libs-[0-9]*:../../x11/qt3-libs
DEPENDS+=	qt3-tools-[0-9]*:../../x11/qt3-tools
DEPENDS+=	qt4-libs-[0-9]*:../../x11/qt4-libs
DEPENDS+=	qt4-tools-[0-9]*:../../x11/qt4-tools

#
# 2. Applications
#
DEPENDS+=	konversation-[0-9]*:../../chat/konversation
DEPENDS+=	konversation-kde3-[0-9]*:../../chat/konversation-kde3
DEPENDS+=	asterisk>=11:../../comms/asterisk
DEPENDS+=	avr-gcc-[0-9]*:../../cross/avr-gcc
DEPENDS+=	avr-libc-[0-9]*:../../cross/avr-libc
DEPENDS+=	avr-gdb-[0-9]*:../../cross/avr-gdb
DEPENDS+=	mysql51-client-[0-9]*:../../databases/mysql51-client
DEPENDS+=	mysql51-server-[0-9]*:../../databases/mysql51-server
DEPENDS+=	mysql55-client-[0-9]*:../../databases/mysql55-client
DEPENDS+=	mysql55-server-[0-9]*:../../databases/mysql55-server
DEPENDS+=	postgresql84-[0-9]*:../../databases/postgresql84
DEPENDS+=	postgresql91-[0-9]*:../../databases/postgresql91
DEPENDS+=	postgresql92-[0-9]*:../../databases/postgresql92
DEPENDS+=	valgrind-[0-9]*:../../devel/valgrind
DEPENDS+=	abiword-[0-9]*:../../editors/abiword
DEPENDS+=	emacs>=24<25:../../editors/emacs24
DEPENDS+=	emacs-packages-[0-9]*:../../editors/emacs-packages
DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
DEPENDS+=	p5-Padre-[0-9]*:../../editors/p5-Padre
DEPENDS+=	glusterfs-[0-9]*:../../filesystems/glusterfs
DEPENDS+=	tahoe-lafs-[0-9]*:../../filesystems/tahoe-lafs
DEPENDS+=	blender-[0-9]*:../../graphics/blender
DEPENDS+=	gimp-[0-9]*:../../graphics/gimp
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz
DEPENDS+=	claws-mail-[0-9]*:../../mail/claws-mail
DEPENDS+=	evolution-[0-9]*:../../mail/evolution
DEPENDS+=	roundcube-[0-9]*:../../mail/roundcube
DEPENDS+=	squirrelmail-[0-9]*:../../mail/squirrelmail
DEPENDS+=	thunderbird-[0-9]*:../../mail/thunderbird
DEPENDS+=	thunderbird-l10n-[0-9]*:../../mail/thunderbird-l10n
DEPENDS+=	thunderbird10-[0-9]*:../../mail/thunderbird10
DEPENDS+=	thunderbird10-l10n-[0-9]*:../../mail/thunderbird10-l10n
DEPENDS+=	R-[0-9]*:../../math/R
DEPENDS+=	octave-[0-9]*:../../math/octave
DEPENDS+=	zyGrib-[0-9]*:../../misc/zyGrib
DEPENDS+=	mplayer-[0-9]*:../../multimedia/mplayer
DEPENDS+=	xine-ui-[0-9]*:../../multimedia/xine-ui
DEPENDS+=	gstreamer0.10-plugins-[0-9]*:../../meta-pkgs/gstreamer0.10-plugins
DEPENDS+=	cups-[0-9]*:../../print/cups
DEPENDS+=	evince-[0-9]*:../../print/evince
DEPENDS+=	lilypond-[0-9]*:../../print/lilypond
DEPENDS+=	mit-krb5-appl-[0-9]*:../../security/mit-krb5-appl
DEPENDS+=	FlightCrew-[0-9]*:../../textproc/FlightCrew
DEPENDS+=	clearsilver-[0-9]*:../../www/clearsilver
DEPENDS+=	mediawiki-[0-9]*:../../www/mediawiki
DEPENDS+=	ruby-rails3-[0-9]*:../../www/ruby-rails3
DEPENDS+=	ruby-rails31-[0-9]*:../../www/ruby-rails31
DEPENDS+=	ruby-rails32-[0-9]*:../../www/ruby-rails32

#
# 3. Libraries
#
DEPENDS+=	db46-[0-9]*:../../databases/db46
DEPENDS+=	db5-[0-9]*:../../databases/db5
DEPENDS+=	heimdal-[0-9]*:../../security/heimdal
DEPENDS+=	mit-krb5-[0-9]*:../../security/mit-krb5

#
# 4. TeX
#
DEPENDS+=	tex-collection-fontsrecommended-[0-9]*:../../fonts/tex-collection-fontsrecommended
DEPENDS+=	tex-collection-fontsrecommended-doc-[0-9]*:../../fonts/tex-collection-fontsrecommended-doc
DEPENDS+=	teTeX-[0-9]*:../../print/teTeX
DEPENDS+=	teTeX3-bin-[0-9]*:../../print/teTeX3-bin
DEPENDS+=	teTeX3-texmf-[0-9]*:../../print/teTeX3-texmf
DEPENDS+=	tex-collection-basic-[0-9]*:../../print/tex-collection-basic
DEPENDS+=	tex-collection-basic-doc-[0-9]*:../../print/tex-collection-basic-doc
DEPENDS+=	tex-collection-documentation-base-doc-[0-9]*:../../print/tex-collection-documentation-base-doc
DEPENDS+=	tex-collection-genericrecommended-[0-9]*:../../print/tex-collection-genericrecommended
DEPENDS+=	tex-collection-genericrecommended-doc-[0-9]*:../../print/tex-collection-genericrecommended-doc
DEPENDS+=	tex-collection-latex-[0-9]*:../../print/tex-collection-latex
DEPENDS+=	tex-collection-latex-doc-[0-9]*:../../print/tex-collection-latex-doc

#
# 5. Desktops
#
DEPENDS+=	deforaos-desktop-[0-9]*:../../meta-pkgs/deforaos-desktop
DEPENDS+=	desktop-gnome-[0-9]*:../../meta-pkgs/desktop-gnome
DEPENDS+=	gnome-[0-9]*:../../meta-pkgs/gnome
DEPENDS+=	gnome-admin-[0-9]*:../../meta-pkgs/gnome-admin
DEPENDS+=	gnome-platform-[0-9]*:../../meta-pkgs/gnome-platform
DEPENDS+=	gnustep-[0-9]*:../../meta-pkgs/gnustep
DEPENDS+=	kde3-[0-9]*:../../meta-pkgs/kde3
DEPENDS+=	kde4-[0-9]*:../../meta-pkgs/kde4
DEPENDS+=	matchbox-[0-9]*:../../meta-pkgs/matchbox
DEPENDS+=	windowmaker-desktop-[0-9]*:../../meta-pkgs/windowmaker-desktop
DEPENDS+=	xfce4-[0-9]*:../../meta-pkgs/xfce4
DEPENDS+=	xfce4-extras-[0-9]*:../../meta-pkgs/xfce4-extras
DEPENDS+=	xview-[0-9]*:../../x11/xview

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
DEPENDS+=	modular-xorg-[0-9]*:../../meta-pkgs/modular-xorg


#
# Note that (unlike in bulk-small) we make no effort to list or track
# depends of the above. In many cases the packages listed above are
# intentionally chosen to bring in other things that we more or less
# want in here.
#

# We are supposed to be a superset of bulk-medium and bulk-small.
DEPENDS+=	bulk-medium-[0-9]*:../../meta-pkgs/bulk-medium
DEPENDS+=	bulk-small-[0-9]*:../../meta-pkgs/bulk-small

.include "../../mk/bsd.pkg.mk"
