# $NetBSD: Makefile,v 1.5 2006/09/09 02:43:09 obache Exp $
#

DISTNAME=	spl-0.9h
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://www.clifford.at/spl/releases/

MAINTAINER=	raphael@raphael.g-system.at
HOMEPAGE=	http://www.clifford.at/spl
COMMENT=	The SPL Programming Language

USE_LANGUAGES=	c
USE_TOOLS+=	bash gmake gawk

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-patch
SUBST_FILES.prefix=	GNUmakefile
SUBST_SED.prefix+=	-e 's,^  prefix.*,  prefix = ${PREFIX},g'
SUBST_SED.prefix+=	-e 's,^  cgibin_libdir.*,  cgibin_libdir = ${PREFIX}/libexec/cgi-bin,g'

#subst.mk does not correctly detect GNUmakefile as text file
_SUBST_IS_TEXT_FILE=true

MAKE_FILE=	GNUmakefile
BUILD_TARGET=	all spldoc
EGDIR=		${PREFIX}/share/examples/spl
DOCDIR=		${PREFIX}/share/doc/spl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/cgi-bin/webspl_cache
	${CHMOD} a+rwx ${PREFIX}/libexec/cgi-bin/webspl_cache
	${LN} -s ${PREFIX}/lib/spl_modules ${PREFIX}/libexec/cgi-bin/spl_modules
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${PAX} -rw -p am README* manual.tex spldoc webspl_demo webspltut ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} example* ${EGDIR}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
