# $NetBSD: Makefile,v 1.4 2024/05/06 08:40:20 jperkin Exp $

DISTNAME=	aiomixer-1.0.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=niacat/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/niacat/aiomixer
COMMENT=	Terminal NetBSD audio mixer / volume control
LICENSE=	2-clause-bsd

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

# Uses NetBSD-only APIs
ONLY_FOR_PLATFORM=	NetBSD-*-*

BUILDLINK_API_DEPENDS.cdk+=	cdk>=5.0.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aiomixer ${DESTDIR}${PREFIX}/bin/aiomixer
	${INSTALL_DATA} ${WRKSRC}/aiomixer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/aiomixer.1

.include "../../devel/cdk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
