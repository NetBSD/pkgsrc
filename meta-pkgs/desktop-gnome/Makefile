# $NetBSD: Makefile,v 1.1.1.1 2009/02/23 17:52:25 ahoka Exp $
#

DISTNAME=	desktop-gnome-0.1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	netbsd-desktop@NetBSD.org
COMMENT=	Software stack for the NetBSD Desktop Project
HOMEPAGE=	http://wiki.netbsd.se/Desktop_Project/

META_PACKAGE=	yes

# implements http://wiki.netbsd.se/Desktop_Phase_1
#
DEPENDS+=	cups-[0-9]*:../../print/cups
DEPENDS+=	firefox3-[0-9]*:../../www/firefox3
DEPENDS+=	gnome-[0-9]*:../../meta-pkgs/gnome
DEPENDS+=	gimp-[0-9]*:../../graphics/gimp
DEPENDS+=	notification-daemon-[0-9]*:../../sysutils/notification-daemon
DEPENDS+=	thunderbird-[0-9]*:../../mail/thunderbird
DEPENDS+=	pidgin-[0-9]*:../../chat/pidgin
DEPENDS+=	pidgin-libnotify-[0-9]*:../../chat/pidgin-libnotify
DEPENDS+=	Transmission-[0-9]*:../../net/Transmission

# useful fonts and themes
#
DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf
DEPENDS+=	liberation-ttf-[0-9]*:../../fonts/liberation-ttf

# the space taken by some major shells shouldnt be a problem
#
DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	tcsh-[0-9]*:../../shells/tcsh
DEPENDS+=	zsh-[0-9]*:../../shells/zsh
DEPENDS+=	mksh-[0-9]*:../../shells/mksh

.include "../../mk/bsd.pkg.mk"
