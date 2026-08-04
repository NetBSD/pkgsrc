# $NetBSD: Makefile,v 1.27 2026/08/04 20:29:06 wiz Exp $

DISTNAME=	eukleides-1.5.4
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://www.eukleides.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.eukleides.org/
COMMENT=	Euclidean geometry drawing language
LICENSE=	gnu-gpl-v3

DEPENDS+=	getopt-[0-9]*:../../misc/getopt

USE_TOOLS+=	bash:run bison gmake lex makeinfo yacc
INFO_FILES=	yes

REPLACE_BASH=	bash/*

BUILDLINK_TRANSFORM+=	l:ncurses:curses

SUBST_CLASSES+=		getopt
SUBST_STAGE.getopt=	pre-configure
SUBST_MESSAGE.getopt=	Replacing getopt.
SUBST_FILES.getopt=	bash/euktoeps
SUBST_SED.getopt+=	-e 's,@GETOPT@,${LOCALBASE}/bin/getopt,'

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			PREFIX=${DESTDIR}${PREFIX}			\
			BIN_DIR=${DESTDIR}${PREFIX}/bin			\
			INFO_DIR=${DESTDIR}${PREFIX}/${PKGINFODIR}	\
			DOC_DIR=${DESTDIR}${PREFIX}/share/eukleides	\
			MAN_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1	\
			TEX_DIR=${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/eukleides

pre-install:
	${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} -f {} \;

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
