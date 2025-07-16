# $NetBSD: Makefile,v 1.1 2025/07/16 19:35:28 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		${GITHUB_PROJECT}-0.0.20201101
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GITHUB:=sysvinit/}
GITHUB_PROJECT=		execshell
GITHUB_TAG=		b0b41d50cdb09f26b7f31e960e078c0500c661f5

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/sysvinit/execshell/
COMMENT=		Proof of concept execline REPL
LICENSE=		isc

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/

.include "../../devel/skalibs/buildlink3.mk"
.include "../../devel/linenoise/buildlink3.mk"
.include "../../lang/execline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
