# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:10 tv Exp $
#

DISTNAME=		MyPasswordSafe-20041004.src
PKGNAME=		MyPasswordSafe-20041004
CATEGORIES=		security
MASTER_SITES=		http://www.semanticgap.com/myps/release/devel/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.semanticgap.com/myps/
COMMENT=		Easy-to-use password manager

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_GNU_TOOLS+=		make
MAKE_FLAGS+=		QMAKE=${QTDIR:Q}/bin/qmake

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
