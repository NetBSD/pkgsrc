# $NetBSD: Makefile,v 1.3 2026/10/25 14:08:12 ktnb Exp $

DISTNAME=	akku-1.2.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITLAB:=-/project/6808260/uploads/44040730f50c8a202e8d39b2c3a8f377/}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://akkuscm.org/
COMMENT=	Scheme package manager
LICENSE=	gnu-gpl-v3

USE_TOOLS=	pkg-config gmake

DEPENDS+=	git-base-[0-9]*:../../devel/git-base
DEPENDS+=	curl-[0-9]*:../../www/curl

GNU_CONFIGURE=	yes

.include "../../lang/guile30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
