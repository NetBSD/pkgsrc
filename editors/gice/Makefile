# $NetBSD: Makefile,v 1.1.1.1 2002/09/06 23:51:13 rh Exp $
#

DISTNAME=		gice-0.6.1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gice/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://gice.sourceforge.net/
COMMENT=		Powerful C text editor with advanced features

USE_X11=		YES
USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

WRKSRC=			${WRKDIR}/gice
ALL_TARGET=		gice

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gice ${PREFIX}/bin

.include "../../x11/gtk2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
