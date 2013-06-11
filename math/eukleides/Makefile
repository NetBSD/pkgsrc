# $NetBSD: Makefile,v 1.21 2013/06/11 23:34:48 dholland Exp $

DISTNAME=	eukleides-1.5.4
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

FIND_PREFIX:=		GETOPTDIR=getopt
.include "../../mk/find-prefix.mk"

SUBST_CLASSES+=		getopt
SUBST_STAGE.getopt=	pre-configure
SUBST_MESSAGE.getopt=	Replacing getopt.
SUBST_FILES.getopt=	bash/euktoeps
SUBST_SED.getopt+=	-e 's,@GETOPT@,${GETOPTDIR}/bin/getopt,'

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			PREFIX=${DESTDIR}${PREFIX}			\
			BIN_DIR=${DESTDIR}${PREFIX}/bin			\
			INFO_DIR=${DESTDIR}${PREFIX}/${PKGINFODIR}	\
			DOC_DIR=${DESTDIR}${PREFIX}/share/eukleides	\
			MAN_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

pre-install:
	${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} -f {} \;

.include "../../mk/curses.buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
