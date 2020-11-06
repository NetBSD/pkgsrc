# $NetBSD: Makefile,v 1.2 2020/11/06 18:04:26 maya Exp $

DISTNAME=	Montserrat-7.210
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=JulietaUla/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/JulietaUla/Montserrat/
COMMENT=	Geometric sans-serif typeface font by Julieta Ulanovsky
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/${DISTNAME}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
