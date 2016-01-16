# $NetBSD: Makefile,v 1.3 2016/01/16 19:02:07 fhajny Exp $

DISTNAME=	p1_zlib-1.0.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/zlib/
COMMENT=	Native zlib driver for Erlang
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	zlib
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
