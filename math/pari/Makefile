# $NetBSD: Makefile,v 1.1.1.1 2001/03/07 20:57:48 jtb Exp $

DISTNAME=		pari-2.1.0
CATEGORIES=		math
MASTER_SITES=		ftp://www.gn-50uma.de/gn/gn-50uma.de/pari-2.1/ \
			http://www.gn-50uma.de/ftp/pari-2.1/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.parigp-home.de
COMMENT=		PARI-GP is a software package for computer-aided number theory

DEPENDS+=		readline>=4.0:../../devel/readline
BUILD_DEPENDS+=		${LOCALBASE}/bin/emacs:../../editors/emacs
BUILD_DEPENDS+= 	${LOCALBASE}/bin/tex:../../print/teTeX

USE_PERL5=		#defined
USE_X11=		#defined
HAS_CONFIGURE=		#defined
CONFIGURE_SCRIPT=	${WRKSRC}/Configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}
EVAL_PREFIX+=		READLINE_PREFIX=readline
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=		X11BASE=${X11BASE}
CONFIGURE_ENV+=		READLINE_PREFIX=${READLINE_PREFIX}
CONFIGURE_ENV+=		miscdir=${PREFIX}/share/pari
CONFIGURE_ARGS+=	--graphic=X11
REPLACE_NCURSES=	${WRKSRC}/Configure

.include "../../mk/bsd.pkg.mk"
