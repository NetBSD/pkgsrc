# $NetBSD: Makefile,v 1.3 1999/09/06 19:04:37 hubertf Exp $
#

DISTNAME=	gtranscript-0.0.1
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

DEPENDS+=	gnome-core-1.0.9:../../x11/gnome-core
DEPENDS+=	postgresql-6.4.2:../../databases/postgresql

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/pgsql/include"

.include "../../mk/bsd.pkg.mk"
