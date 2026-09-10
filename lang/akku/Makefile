# $NetBSD: Makefile,v 1.2 2026/09/10 13:06:43 ktnb Exp $

DISTNAME=	akku-1.1.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITLAB:=akkuscm/akku/uploads/819fd1f988c6af5e7df0dfa70aa3d3fe/}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://akkuscm.org/
COMMENT=	Scheme package manager
LICENSE=	gnu-gpl-v3

USE_TOOLS=	pkg-config gmake

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

GNU_CONFIGURE=	yes

.include "../../lang/guile30/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
