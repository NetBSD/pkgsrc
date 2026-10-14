#	$NetBSD: Makefile,v 1.1 2026/10/14 03:34:55 riastradh Exp $
#

.include "../../mail/dkim-rotate/Makefile.common"

PKGNAME=	${DISTNAME:C/^dkim-rotate-dkim-rotate-/dkim-rotate-doc-/}

COMMENT=	Documentation for dkim-rotate

USE_LANGUAGES=	# none

USE_TOOLS+=	gmake

TOOL_DEPENDS+=		pandoc-cli>=0:../../converters/pandoc-cli
TOOLS_CREATE+=		pandoc
TOOLS_PATH.pandoc=	${TOOLDIR}/bin/pandoc

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PKGMANDIR}/man7
INSTALLATION_DIRS+=	share/doc/dkim-rotate

MAKE_FLAGS+=	SHELL=${SHELL:Q}

do-install:
	${RUN}${INSTALL_MAN} ${WRKSRC:Q}/dkim-rotate.1 \
	    ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man1
	${RUN}${INSTALL_MAN} ${WRKSRC:Q}/dkim-rotate.5 \
	    ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man5
	${RUN}${INSTALL_MAN} ${WRKSRC:Q}/dkim-rotate.7 \
	    ${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}/man7
	${RUN}${INSTALL_DATA} ${WRKSRC:Q}/*.html \
	    ${DESTDIR:Q}${PREFIX:Q}/share/doc/dkim-rotate/

.include "../../mk/bsd.pkg.mk"
