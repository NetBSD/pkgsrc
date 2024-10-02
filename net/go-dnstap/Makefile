# $NetBSD: Makefile,v 1.68 2024/10/02 15:25:58 schmonz Exp $

DISTNAME=		go-dnstap-0.4.0
PKGREVISION=		41
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=dnstap/}
GITHUB_PROJECT=		golang-dnstap
GITHUB_TAG=		v${PKGVERSION_NOREV}

HOMEPAGE=		https://github.com/dnstap/golang-dnstap
COMMENT=		Go language implementation of framestream protocol
LICENSE=		apache-2.0

GO_BUILD_PATTERN=	./dnstap

INSTALLATION_DIRS=	${PKGMANDIR}/man8

post-install:
	${INSTALL_MAN} ${WRKSRC}/dnstap/dnstap.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
