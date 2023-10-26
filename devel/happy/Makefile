# $NetBSD: Makefile,v 1.13 2023/10/26 05:41:00 pho Exp $

DISTNAME=	happy-1.21.0
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Parser generator for Haskell
LICENSE=	modified-bsd

USE_TOOLS+=	autoconf gmake
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

# happy tries to use itself in the building process of the test suite but
# the current version of Cabal (shipped with GHC 9.6) doesn't support it
# yet. We must disable the test suite for now.
SUBST_CLASSES+=		tests
SUBST_STAGE.tests=	post-extract
SUBST_FILES.tests=	happy.cabal
SUBST_SED.tests+=	-e '/test-suite tests/a\${.newline}  buildable: False'
SUBST_SED.tests+=	-e '/build-tools: happy/d'
CONFIGURE_ARGS+=	-f-bootstrap

CONFIGURE_ENV+=	fp_cv_dir_docbook_xsl=${PREFIX}/share/xsl/docbook
CONFIGURE_ENV+=	ac_cv_path_DbLatexCmd= # empty
pre-configure:
	${RUN}cd ${WRKSRC}/doc && autoconf && ${PKGSRC_SETENV} ${CONFIGURE_ENV} \
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} ./configure

post-build:
	${RUN}cd ${WRKSRC}/doc && ${GMAKE}

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PREFIX}/share/doc/${PKGBASE}
post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/happy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	for f in ${WRKSRC}/doc/happy/*; do \
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/; \
	done

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
