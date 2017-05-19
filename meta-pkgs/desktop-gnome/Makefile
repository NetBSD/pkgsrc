# $NetBSD: Makefile,v 1.12 2017/05/19 13:18:17 prlw1 Exp $
#

DISTNAME=	desktop-gnome-0.5
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11 gnome
MASTER_SITES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Software stack for the NetBSD Desktop Project
HOMEPAGE=	http://wiki.netbsd.se/Desktop_Project

META_PACKAGE=	yes

# implements http://wiki.netbsd.se/Desktop_Phase_1
#
DEPENDS+=	pkgin-[0-9]*:../../pkgtools/pkgin
DEPENDS+=	cups-[0-9]*:../../print/cups
DEPENDS+=	firefox-[0-9]*:../../www/firefox
DEPENDS+=	gnome-[0-9]*:../../meta-pkgs/gnome
DEPENDS+=	gimp-[0-9]*:../../graphics/gimp
DEPENDS+=	notification-daemon-[0-9]*:../../sysutils/notification-daemon
DEPENDS+=	thunderbird-[0-9]*:../../mail/thunderbird
DEPENDS+=	pidgin-[0-9]*:../../chat/pidgin
DEPENDS+=	pidgin-libnotify-[0-9]*:../../chat/pidgin-libnotify
#DEPENDS+=	transmission-gtk-[0-9]*:../../net/transmission-gtk
DEPENDS+=	filezilla-[0-9]*:../../net/filezilla

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
