# $NetBSD: Makefile,v 1.12 2001/09/27 23:17:52 jlam Exp $
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
COMMENT=	SQL Database Client with GNOME frontend

DEPENDS+=	gnome-core-[0-9]*:../../x11/gnome-core
DEPENDS+=	postgresql-{6.5.3*,7.0*,lib-[0-9]*}:../../databases/postgresql-lib

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

CPPFLAGS+=	-I${LOCALBASE}/include		# pgsql/*.h

.include "../../mk/bsd.pkg.mk"
