# $NetBSD: Makefile,v 1.6 2001/05/04 17:14:08 jtb Exp $

DISTNAME=		pari-2.1.0
CATEGORIES=		math
MASTER_SITES=		ftp://www.gn-50uma.de/gn/gn-50uma.de/pari-2.1/ \
			http://www.gn-50uma.de/ftp/pari-2.1/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.parigp-home.de
COMMENT=		software package for computer-aided number theory

DEPENDS+=		readline>=4.0:../../devel/readline
BUILD_DEPENDS+=		emacs-[0-9]*:../../editors/emacs
BUILD_DEPENDS+= 	teTeX-[0-9]*:../../print/teTeX

USE_PERL5=		#defined
USE_X11=		#defined

HAS_CONFIGURE=		#defined
CONFIGURE_SCRIPT=	${WRKSRC}/Configure
REPLACE_NCURSES=	${WRKSRC}/Configure

CONFIGURE_ARGS+=	--prefix=${PREFIX}

READLINE_PREFIX_DEFAULT=${LOCALBASE}
EVAL_PREFIX+=		READLINE_PREFIX=readline
CONFIGURE_ENV+=		READLINE_PREFIX=${READLINE_PREFIX}

CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

CONFIGURE_ENV+=		X11BASE=${X11BASE}
CONFIGURE_ARGS+=	--graphic=X11
CONFIGURE_ENV+=		miscdir=${PREFIX}/share/pari

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pari
	cd ${WRKSRC}/examples/ && ${INSTALL_DATA} EXPLAIN *.gp	\
		matexp.c Inputrc ${PREFIX}/share/examples/pari

.include "../../mk/bsd.pkg.mk"
