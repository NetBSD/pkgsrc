# $NetBSD: Makefile,v 1.15 2009/02/09 22:56:23 joerg Exp $
#

DISTNAME=		tailor-0.9.35
PKGREVISION=		2
CATEGORIES=		devel scm
MASTER_SITES=		http://darcs.arstecnica.it/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://wiki.darcs.net/DarcsWiki/Tailor
COMMENT=		Tool to migrate changesets between various version control systems

PKG_DESTDIR_SUPPORT=	user-destdir

#LICENSE=		GPLv3
PYDISTUTILSPKG=		yes
PYTHON_PATCH_SCRIPTS=	tailor

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/README* ${DESTDIR}${PREFIX}/share/doc/tailor

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
