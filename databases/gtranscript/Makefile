# $NetBSD: Makefile,v 1.20 2003/09/19 23:08:24 dent Exp $
#

DISTNAME=	gtranscript-0.0.1
PKGREVISION=	4
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
USE_BUILDLINK2=	YES
USE_X11BASE=	YES

CPPFLAGS+=	-I${LOCALBASE}/include		# <postgresql/*.h>

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
