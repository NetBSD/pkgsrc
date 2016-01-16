# $NetBSD: Makefile,v 1.2 2016/01/16 17:31:45 fhajny Exp $

DISTNAME=	p1_tls-1.0.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/tls/
COMMENT=	TLS/SSL native driver for Erlang
LICENSE=	gnu-gpl-v2

GITHUB_PROJECT=	tls
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

GNU_CONFIGURE=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
