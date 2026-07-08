# $NetBSD: Makefile,v 1.4 2026/07/08 15:44:41 micha Exp $

DISTNAME=	ajbsp-v1.05
PKGNAME=	${DISTNAME:S/v//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITLAB:=andwj/}
GITLAB_PROJECT=	ajbsp
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://gitlab.com/andwj/ajbsp
COMMENT=	Node builder for modern DOOM source ports
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c++
USE_CXX_FEATURES+=	c++11
USE_TOOLS+=		gmake

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
