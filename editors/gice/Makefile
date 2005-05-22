# $NetBSD: Makefile,v 1.20 2005/05/22 20:07:56 jlam Exp $
#

DISTNAME=		gice-0.6.2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gice/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gice.sourceforge.net/
COMMENT=		Powerful C text editor with advanced features

WRKSRC=			${WRKDIR}/gice
USE_X11=		YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES

BUILD_TARGET=		gice

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gice ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
