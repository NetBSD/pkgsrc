# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:33 jlam Exp $
#

DISTNAME=		MyPasswordSafe-20050615.src
PKGNAME=		MyPasswordSafe-20050615
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		http://www.semanticgap.com/myps/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.semanticgap.com/myps/
COMMENT=		Easy-to-use password manager

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake
MAKE_FLAGS+=		QMAKE=${QTDIR:Q}/bin/qmake

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
