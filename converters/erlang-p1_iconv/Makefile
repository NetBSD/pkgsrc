# $NetBSD: Makefile,v 1.3 2016/01/16 18:49:22 fhajny Exp $

DISTNAME=	p1_iconv-0.9.0
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/eiconv/
COMMENT=	Erlang iconv binding
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	eiconv
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
