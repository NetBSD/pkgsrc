# $NetBSD: Makefile,v 1.3 2013/03/24 16:21:56 dholland Exp $
#

DISTNAME=	reposurgeon-2.26
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.catb.org/~esr/reposurgeon/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/reposurgeon/
COMMENT=	Tool for editing version-control repository history
LICENSE=	modified-bsd

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_LANGUAGES=	# none

REPLACE_SH=	repopuller

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Set PYTHONBIN
SUBST_FILES.py=		repodiffer
SUBST_FILES.py+=	reposurgeon
SUBST_SED.py=		-e 's,/usr/bin/env python,${PYTHONBIN},'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/reposurgeon

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/repodiffer \
			${WRKSRC}/repopuller \
			${WRKSRC}/reposurgeon \
		${DESTDIR}${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/repodiffer.1 \
			${WRKSRC}/repopuller.1 \
			${WRKSRC}/reposurgeon.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

	${INSTALL_DATA} ${WRKSRC}/COPYING \
			${WRKSRC}/README \
			${WRKSRC}/NEWS \
			${WRKSRC}/conversion.mk \
		${DESTDIR}${PREFIX}/share/doc/reposurgeon

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
