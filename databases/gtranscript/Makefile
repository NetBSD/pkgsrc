# $NetBSD: Makefile,v 1.14 2003/01/05 20:14:22 jlam Exp $
#

DISTNAME=	gtranscript-0.0.1
PKGREVISION=	2
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
DEPENDS+=	postgresql-lib>=7.3.1:../../databases/postgresql-lib

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

CPPFLAGS+=	-I${LOCALBASE}/include		# <postgresql/*.h>

.include "../../mk/bsd.pkg.mk"
