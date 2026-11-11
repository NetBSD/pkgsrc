# $NetBSD: Makefile,v 1.86.2.2 2026/11/11 20:32:03 maya Exp $

DISTNAME=		postforward-1.1.1
PKGREVISION=		30
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=zoni/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/zoni/postforward
COMMENT=		Postfix Sender Rewriting Scheme forwarding agent
LICENSE=		2-clause-bsd

CHECK_RELRO_SKIP+=	bin/postforward

post-extract:
	${CP} ${FILESDIR}/go.mod ${WRKSRC}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
