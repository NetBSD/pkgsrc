# $NetBSD: Makefile,v 1.12 2026/05/07 18:50:09 bsiegert Exp $

DISTNAME=	gron-0.7.1
PKGREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=tomnomnom/}
GITHUB_PROJECT=	gron
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tomnomnom/gron
COMMENT=	Transform JSON into discrete assignments for easier searching
LICENSE=	mit

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "go-modules.mk"

post-install:
	${INSTALL_MAN} ${FILESDIR}/gron.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
