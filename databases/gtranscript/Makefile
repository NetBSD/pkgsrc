# $NetBSD: Makefile,v 1.13 2002/03/13 17:36:44 fredb Exp $
#

DISTNAME=	gtranscript-0.0.1
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://gtranscript.linuxbox.com/ \
		ftp://ftp.matrix.com.br/pub/linuxberg/files/gnome/office/ \
		ftp://ftp.abordo.com.br/pub/linuxberg/files/gnome/office/ \
		ftp://ftp.interpath.net/pub/linuxberg/files/gnome/office/ \
		ftp://ftp.iinet.net.au/mirrors1/berg/files/gnome/office/ \
		ftp://ftp.online.be/raid/linuxberg/files/gnome/office/ \
		ftp://ftp.univie.ac.at/systems/linux/linuxberg/files/gnome/office/ \
		ftp://ftp.univie.ac.at/systems/linux/linuxberg/files/gnome/office/ \
		ftp://ftp.sunsite.auc.dk/disk2/linuxberg.com/files/gnome/office/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gtranscript.linuxbox.com/
COMMENT=	SQL Database Client with GNOME frontend

DEPENDS+=	gnome-core>=1.4.0.4nb1:../../x11/gnome-core
DEPENDS+=	postgresql-{6.5.3*,7.0*,lib-[0-9]*}:../../databases/postgresql-lib

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

CPPFLAGS+=	-I${LOCALBASE}/include		# pgsql/*.h

.include "../../mk/bsd.pkg.mk"
