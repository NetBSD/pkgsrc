# $NetBSD: Makefile,v 1.14 2022/01/09 20:06:05 pho Exp $

DISTNAME=	fuse-pcachefs-0.3
PKGREVISION=	3
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=ibizaman/}
GITHUB_PROJECT=	pcachefs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibizaman/pcachefs
COMMENT=	FUSE-based persistent caching filesystem
LICENSE=	apache-2.0

USE_PKG_RESOURCES=	yes

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
EGG_NAME=	pCacheFS-${PKGVERSION_NOREV}

# It's not been ported to Python 3, and the upstream seems to be dead
# atm.
PYTHON_VERSIONS_ACCEPTED=	27

INSTALLATION_DIRS+=	share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} "${WRKSRC}/README.md" \
		"${DESTDIR}${PREFIX}/share/doc/${PKGBASE}"

.include "../../filesystems/py-fuse-bindings/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
