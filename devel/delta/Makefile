# $NetBSD: Makefile,v 1.16 2023/12/22 17:49:32 zafer Exp $

DISTNAME=	delta-2006.08.03
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	#

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://delta.tigris.org/
COMMENT=	Heuristically minimizes interesting files
LICENSE=	2-clause-bsd

USE_TOOLS+=		gmake perl:run
REPLACE_PERL=		delta multidelta
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/delta ${DESTDIR}${PREFIX}/bin/delta
	${INSTALL_SCRIPT} ${WRKSRC}/multidelta ${DESTDIR}${PREFIX}/bin/multidelta
	${INSTALL_PROGRAM} ${WRKSRC}/topformflat ${DESTDIR}${PREFIX}/bin/topformflat

.include "../../mk/bsd.pkg.mk"
