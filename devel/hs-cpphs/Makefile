# $NetBSD: Makefile,v 1.13 2020/08/19 07:50:52 pho Exp $

DISTNAME=		cpphs-1.20.8
CATEGORIES=		devel

MAINTAINER=		esg@sdf.lonestar.org
COMMENT=		Liberalised re-implementation of cpp, the C pre-processor
LICENSE=		gnu-lgpl-v2.1

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# I don't know why but an rpath to ${WRKSRC}/dist/build/cpphs started
# appearing in the resulting binary, even though there are no actual
# libraries to find in that directory at runtime. Cabal seems to be
# doing something strange. Will need to investigate it later. (pho@)
CHECK_SHLIBS_SKIP+= bin/cpphs

.include "../../mk/haskell.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../time/hs-old-time/buildlink3.mk"
.include "../../textproc/hs-polyparse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
