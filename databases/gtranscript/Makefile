# $NetBSD: Makefile,v 1.25 2004/07/24 22:45:14 recht Exp $
#

DISTNAME=	gtranscript-0.0.1
PKGREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.matrix.com.br/pub/linuxberg/files/gnome/office/ \
		ftp://ftp.abordo.com.br/pub/linuxberg/files/gnome/office/ \
		ftp://ftp.interpath.net/pub/linuxberg/files/gnome/office/ \
		ftp://ftp.iinet.net.au/mirrors1/berg/files/gnome/office/ \
		ftp://ftp.online.be/raid/linuxberg/files/gnome/office/ \
		ftp://ftp.univie.ac.at/systems/linux/linuxberg/files/gnome/office/ \
		ftp://ftp.univie.ac.at/systems/linux/linuxberg/files/gnome/office/ \
		ftp://ftp.sunsite.auc.dk/disk2/linuxberg.com/files/gnome/office/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtranscript.sourceforge.net/
COMMENT=	SQL Database Client with GNOME frontend

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_X11BASE=	YES

#CPPFLAGS+=	-I${LOCALBASE}/include		# <postgresql/*.h>

.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
