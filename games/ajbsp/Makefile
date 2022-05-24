# $NetBSD: Makefile,v 1.3 2022/05/24 10:07:06 nikita Exp $

DISTNAME=	ajbsp-v1.01
PKGNAME=	${DISTNAME:S/v//}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITLAB:=andwj/}
GITLAB_PROJECT=	ajbsp
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://gitlab.com/andwj/ajbsp
COMMENT=	Node builder for modern DOOM source ports
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
