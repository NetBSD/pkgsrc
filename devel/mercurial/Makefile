# $NetBSD: Makefile,v 1.17 2008/04/25 20:39:08 joerg Exp $
#

DISTNAME=	mercurial-1.0
CATEGORIES=	devel scm
MASTER_SITES=	http://www.selenic.com/mercurial/release/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.selenic.com/mercurial/wiki/index.cgi/Mercurial
COMMENT=	Fast, lightweight source control management system

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

PY_PATCHPLIST=	yes
PYDISTUTILSPKG=	yes
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.5  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/mercurial
	${INSTALL_DATA} ${WRKSRC}/README  \
		${DESTDIR}${PREFIX}/share/doc/mercurial

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
