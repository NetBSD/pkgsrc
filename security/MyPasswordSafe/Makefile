# $NetBSD: Makefile,v 1.6 2006/01/05 10:08:59 ghen Exp $
#

DISTNAME=		MyPasswordSafe-20050615.src
PKGNAME=		MyPasswordSafe-20050615
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
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/bsd.pkg.mk"
