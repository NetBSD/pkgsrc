# $NetBSD: Makefile,v 1.1 2012/10/14 17:51:15 minskim Exp $

DISTNAME=	texlive-docindex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2012
TEXLIVE_REV=	27926

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-texlive-docindex

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to documentation files.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	doc.html
SUBST_SED.paths=	-e 's,<a href="texmf,<a href="../../texmf,g'

INSTALLATION_DIRS+=	share/doc/texlive

.include "../../print/texlive/package.mk"

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc.html \
		${DESTDIR}${PREFIX}/share/doc/texlive/

.include "../../mk/bsd.pkg.mk"
