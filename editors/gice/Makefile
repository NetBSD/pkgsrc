# $NetBSD: Makefile,v 1.16 2004/12/03 15:14:56 wiz Exp $
#

DISTNAME=		gice-0.6.1
PKGREVISION=		6
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gice/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://gice.sourceforge.net/
COMMENT=		Powerful C text editor with advanced features

WRKSRC=			${WRKDIR}/gice
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

BUILD_TARGET=		gice

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gice ${PREFIX}/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
