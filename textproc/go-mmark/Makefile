# $NetBSD: Makefile,v 1.46 2022/07/13 16:03:01 bsiegert Exp $

DISTNAME=	mmark-2.2.10
PKGNAME=	go-${DISTNAME}
PKGREVISION=	14
MASTER_SITES=	${MASTER_SITE_GITHUB:=mmarkdown/}
CATEGORIES=	textproc
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/miekg/mmark
COMMENT=	Powerful markdown processor in Go geared towards the IETF
LICENSE=	2-clause-bsd

GO_BUILD_PATTERN=	.
INSTALLATION_DIRS+=	man/man1

.include "go-modules.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/mmark.1 ${DESTDIR}${PREFIX}/man/man1

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
