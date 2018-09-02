# $NetBSD: Makefile,v 1.1 2018/09/02 20:27:40 spz Exp $

DISTNAME=		postforward-1.1.0
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=zoni/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/zoni/postforward
COMMENT=		Postfix Sender Rewriting Scheme forwarding agent
LICENSE=		2-clause-bsd

GO_SRCPATH=		github.com/zoni/postforward
GO_DIST_BASE=		${DISTNAME}

CHECK_RELRO_SKIP+=	bin/postforward

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
