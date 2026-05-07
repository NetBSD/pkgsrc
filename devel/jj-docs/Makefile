# $NetBSD: Makefile,v 1.8 2026/05/07 21:19:51 wiz Exp $

DISTNAME=	jj-v0.41.0-docs-html
PKGNAME=	${DISTNAME:S/jj-v/jj-docs-/:S/-docs-html//}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jj-vcs/jj/releases/download/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/martinvonz/jj/
COMMENT=	Documentation for jj
LICENSE=	apache-2.0

USE_TOOLS+=	pax

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS+=	share/doc/jj

do-build:

do-install:
	cd ${WRKSRC} && pax -pp -rw [A-z]* ${DESTDIR}${PREFIX}/share/doc/jj

.include "../../mk/bsd.pkg.mk"
