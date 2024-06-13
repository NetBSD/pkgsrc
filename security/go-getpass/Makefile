# $NetBSD: Makefile,v 1.13 2024/06/13 13:47:07 bsiegert Exp $

DISTNAME=	getpass-0.2.3
PKGNAME=	go-${DISTNAME}
PKGREVISION=	11
MASTER_SITES=	${MASTER_SITE_GITHUB:=jschauma/}
CATEGORIES=	security
GITHUB_PROJECT=	getpass
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	https://github.com/jschauma/getpass
COMMENT=	a Go module to get a password
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/jschauma/getpass

post-build:
	rm -f ${WRKDIR}/bin/example

post-install:
	mkdir -p ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/getpass.1 \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
