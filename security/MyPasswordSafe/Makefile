# $NetBSD: Makefile,v 1.11 2006/03/29 22:14:18 wiz Exp $
#

DISTNAME=		MyPasswordSafe-20060326.src
PKGNAME=		MyPasswordSafe-20060326
CATEGORIES=		security
MASTER_SITES=		http://www.semanticgap.com/myps/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.semanticgap.com/myps/
COMMENT=		Easy-to-use password manager

.include "options.mk"

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake
MAKE_FLAGS+=		QMAKE=${QTDIR:Q}/bin/qmake

.include "../../mk/bsd.pkg.mk"
