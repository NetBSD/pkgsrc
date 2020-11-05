# $NetBSD: Makefile,v 1.41 2020/11/05 09:08:34 ryoon Exp $
#

DISTNAME=	spl-1.0pre3
PKGREVISION=	25
CATEGORIES=	lang
MASTER_SITES=	http://www.clifford.at/spl/releases/
MASTER_SITES+=	http://www.clifford.at/spl/releases/OLD/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.clifford.at/spl/
COMMENT=	The SPL Programming Language
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash gmake gawk pax

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-patch
SUBST_FILES.prefix=	GNUmakefile
SUBST_SED.prefix+=	-e 's,^  prefix.*,  prefix = ${PREFIX},g'
SUBST_SED.prefix+=	-e 's,^ENABLE_OPENGL_SUPPORT.*,ENABLE_OPENGL_SUPPORT=0,g'
SUBST_SED.prefix+=	-e 's,^  cgibin_libdir.*,  cgibin_libdir = ${PREFIX}/libexec/cgi-bin,g'

#subst.mk does not correctly detect GNUmakefile as text file
_SUBST_IS_TEXT_FILE=	true

MAKE_ENV+=	ENABLE_OPENGL_SUPPORT=0
MAKE_FILE=	GNUmakefile
BUILD_TARGET=	all spldoc
EGDIR=		${PREFIX}/share/examples/spl
DOCDIR=		${PREFIX}/share/doc/spl

.include "options.mk"

INSTALLATION_DIRS+=	libexec/cgi-bin/webspl_cache

post-install:
	${CHMOD} a+rwx ${DESTDIR}${PREFIX}/libexec/cgi-bin/webspl_cache
	${LN} -sf ${PREFIX}/lib/spl_modules ${DESTDIR}${PREFIX}/libexec/cgi-bin/spl_modules
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && pax -rw -p am README* manual.tex spldoc webspl_demo webspltut qtdemo ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} example* ${DESTDIR}${EGDIR}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
