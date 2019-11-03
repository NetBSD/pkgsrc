# $NetBSD: Makefile,v 1.11 2019/11/03 10:39:14 rillig Exp $

DISTNAME=		cpphs-1.19.2
PKGREVISION=		1
CATEGORIES=		devel

MAINTAINER=		esg@sdf.lonestar.org
COMMENT=		Liberalised re-implementation of cpp, the C pre-processor
LICENSE=		gnu-lgpl-v2.1

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/haskell.mk"
.include "../../textproc/hs-polyparse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
