# $NetBSD: Makefile,v 1.1.1.1 2000/11/27 23:28:23 jtb Exp $

DISTNAME=	felt-3.05.src
PKGNAME=	felt-3.05
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/FElt/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://felt.sourceforge.net/

DEPENDS+=	readline-[0-9]*:../../devel/readline

WRKSRC=		${WRKDIR}/FElt-3.05
NO_CONFIGURE=	YES
EVAL_PREFIX+=	RL_PREFIX=readline
USE_X11=	YES
USE_XAW=	YES
XAW_TYPE=	3d

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/felt
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/felt
	@for i in FAQ* README* COPYING CHANGELOG TODO; do \
	${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/felt; done
	@for i in ${WRKSRC}/examples/*;	do \
	${INSTALL_DATA} $$i ${PREFIX}/share/examples/felt; done

.include "../../mk/bsd.pkg.mk"
