# $NetBSD: Makefile,v 1.13 2004/01/22 08:30:30 grant Exp $
#

DISTNAME=		gice-0.6.1
PKGREVISION=		5
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gice/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://gice.sourceforge.net/
COMMENT=		Powerful C text editor with advanced features

WRKSRC=			${WRKDIR}/gice
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

ALL_TARGET=		gice

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gice ${PREFIX}/bin

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
