# $NetBSD: Makefile,v 1.9 2022/01/18 02:48:02 pho Exp $

DISTNAME=	alex-3.2.6
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Tool for generating lexical analysers in Haskell
LICENSE=	modified-bsd

USE_TOOLS+=	autoconf gmake
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
BUILD_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

CONFIGURE_ENV+=	fp_cv_dir_docbook_xsl=${PREFIX}/share/xsl/docbook
CONFIGURE_ENV+=	ac_cv_path_DbLatexCmd= # empty
pre-configure:
	${RUN}cd ${WRKSRC}/doc && autoconf && ${PKGSRC_SETENV} ${CONFIGURE_ENV} \
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} ./configure

post-build:
	${RUN}cd ${WRKSRC}/doc && ${GMAKE}

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PREFIX}/share/doc/${PKGBASE}
post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/alex.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	for f in ${WRKSRC}/doc/alex/*; do \
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/; \
	done

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
