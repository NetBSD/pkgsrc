# $NetBSD: Makefile,v 1.8 2006/01/24 07:32:32 wiz Exp $
#

DISTNAME=		MyPasswordSafe-20050615.src
PKGNAME=		MyPasswordSafe-20050615
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://www.semanticgap.com/myps/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.semanticgap.com/myps/
COMMENT=		Easy-to-use password manager

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake
MAKE_FLAGS+=		QMAKE=${QTDIR:Q}/bin/qmake

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
