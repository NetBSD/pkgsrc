# $NetBSD: Makefile,v 1.7 2001/05/19 17:31:05 jtb Exp $

DISTNAME=		pari-2.1.1
CATEGORIES=		math
MASTER_SITES=		ftp://www.gn-50uma.de/gn/gn-50uma.de/pari-2.1/ \
			http://www.gn-50uma.de/ftp/pari-2.1/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.parigp-home.de
COMMENT=		software package for computer-aided number theory

DEPENDS+=		readline>=4.0:../../devel/readline
BUILD_DEPENDS+= 	teTeX-[0-9]*:../../print/teTeX

USE_PERL5=		yes

USE_X11=		yes

USE_CURSES=		yes
REPLACE_NCURSES=	${WRKSRC}/Configure

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/Configure

CONFIGURE_ARGS+=	--prefix=${PREFIX} --share-prefix=${PREFIX}/share

CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=		X11BASE=${X11BASE}

CONFIGURE_ARGS+=	--graphic=X11

.include "../../mk/bsd.pkg.mk"
