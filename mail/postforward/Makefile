# $NetBSD: Makefile,v 1.63 2024/06/01 14:02:54 bsiegert Exp $

DISTNAME=		postforward-1.1.1
PKGREVISION=		5
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
