# $NetBSD: Makefile,v 1.31 2019/09/02 13:19:39 adam Exp $

DISTNAME=		tailor-0.9.35
PKGREVISION=		6
CATEGORIES=		devel scm
MASTER_SITES=		http://darcs.arstecnica.it/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wiki.darcs.net/DarcsWiki/Tailor
COMMENT=		Tool to migrate changesets between various version control systems
LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		#none

PYTHON_VERSIONS_ACCEPTED=   27 # not yet ported as of 0.9.35
REPLACE_PYTHON=		tailor

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/share/doc/tailor

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
