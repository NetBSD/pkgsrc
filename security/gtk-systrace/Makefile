# $NetBSD: Makefile,v 1.7 2004/01/20 12:25:33 agc Exp $
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
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES

pre-configure:
	cd ${WRKSRC} && \
		${ACLOCAL} && \
		${AUTOHEADER} && \
		${AUTOCONF} && \
		${AUTOMAKE} -acf

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
