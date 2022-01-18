# $NetBSD: Makefile,v 1.16 2022/01/18 02:48:06 pho Exp $

DISTNAME=		cpphs-1.20.9.1
#PKGNAME=		${DISTNAME} # XXX: This should probably be renamed to devel/cpphs.
PKGREVISION=		2
CATEGORIES=		devel

MAINTAINER=		esg@sdf.lonestar.org
COMMENT=		Liberalised re-implementation of cpp, the C pre-processor
LICENSE=		gnu-lgpl-v2.1

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../textproc/hs-polyparse/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
