# $NetBSD: Makefile,v 1.3 2023/09/06 18:59:38 schmonz Exp $

DISTNAME=	xe-1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/leahneukirchen/xe/
COMMENT=	Simple xargs and apply replacement
LICENSE=	public-domain

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}

.include "../../mk/bsd.pkg.mk"
