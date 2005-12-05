# $NetBSD: Makefile,v 1.13 2005/12/05 20:50:56 rillig Exp $
#

DISTNAME=	gtk-systrace-2002-12-01
PKGNAME=	gtk-systrace-20021201
PKGREVISION=	3
CATEGORIES=	security x11
MASTER_SITES=	http://www.citi.umich.edu/u/provos/systrace/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.citi.umich.edu/u/provos/systrace/index.html
COMMENT=	GTK interface to systrace(1)

ONLY_FOR_PLATFORM=	NetBSD-1.6[H-Z]*-* NetBSD-[2-9]*-*

WRKSRC=			${WRKDIR}/notification-0.1
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		automake

pre-configure:
	cd ${WRKSRC} && aclocal && autoheader && autoconf && automake -acf

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
