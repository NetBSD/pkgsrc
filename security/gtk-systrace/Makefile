# $NetBSD: Makefile,v 1.8 2004/04/25 05:04:52 snj Exp $
#

DISTNAME=	gtk-systrace-2002-12-01
PKGNAME=	gtk-systrace-20021201
PKGREVISION=	2
CATEGORIES=	security x11
MASTER_SITES=	http://www.citi.umich.edu/u/provos/systrace/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.citi.umich.edu/u/provos/systrace/index.html
COMMENT=	GTK interface to systrace(1)

ONLY_FOR_PLATFORM=	NetBSD-1.6[H-Z]*-* NetBSD-1.[7-9]*-* NetBSD-[2-9]*

WRKSRC=			${WRKDIR}/notification-0.1
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

pre-configure:
	cd ${WRKSRC} && \
		${ACLOCAL} && \
		${AUTOHEADER} && \
		${AUTOCONF} && \
		${AUTOMAKE} -acf

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
