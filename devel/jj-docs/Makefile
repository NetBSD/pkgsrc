# $NetBSD: Makefile,v 1.1 2025/02/05 13:41:29 wiz Exp $

DISTNAME=	jj-v0.25.0-docs-html
PKGNAME=	${DISTNAME:S/jj-v/jj-docs-/:S/-docs-html//}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jj-vcs/jj/releases/download/v0.25.0/

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
