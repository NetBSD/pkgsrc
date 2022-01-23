# $NetBSD: Makefile,v 1.1 2022/01/23 19:42:33 schmonz Exp $

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	xe-0.11
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=leahneukirchen/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/leahneukirchen/xe/
COMMENT=	Simple xargs and apply replacement
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/${DISTNAME}

MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}

.include "../../mk/bsd.pkg.mk"
