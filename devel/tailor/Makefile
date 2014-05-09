# $NetBSD: Makefile,v 1.24 2014/05/09 07:37:03 wiz Exp $

DISTNAME=		tailor-0.9.35
PKGREVISION=		5
CATEGORIES=		devel scm
MASTER_SITES=		http://darcs.arstecnica.it/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wiki.darcs.net/DarcsWiki/Tailor
COMMENT=		Tool to migrate changesets between various version control systems
LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		#none

PYTHON_VERSIONS_INCOMPATIBLE=  33 34 # not yet ported as of 0.9.35
REPLACE_PYTHON=		tailor

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/share/doc/tailor

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
