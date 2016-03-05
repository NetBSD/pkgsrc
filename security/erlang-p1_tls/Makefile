# $NetBSD: Makefile,v 1.3 2016/03/05 11:29:20 jperkin Exp $

DISTNAME=	p1_tls-1.0.0
PKGREVISION=	1
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
