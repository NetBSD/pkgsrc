# $NetBSD: Makefile,v 1.26 2006/02/05 23:08:56 joerg Exp $
#

DISTNAME=		gice-0.6.2
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gice/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gice.sourceforge.net/
COMMENT=		Powerful C text editor with advanced features

WRKSRC=			${WRKDIR}/gice
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES

BUILD_TARGET=		gice
INSTALLATION_DIRS=	bin

.include "../../x11/gtk2/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gice ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
