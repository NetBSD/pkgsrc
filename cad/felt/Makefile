# $NetBSD: Makefile,v 1.3 2001/02/10 16:56:33 jtb Exp $

DISTNAME=	felt-3.05.src
PKGNAME=	felt-3.05
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/FElt/
DISTFILES=	felt-3.05.src.tar.gz felt-3.05.ps.gz

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://felt.sourceforge.net/

DEPENDS+=	readline-[0-9]*:../../devel/readline

EXTRACT_ONLY=	felt-3.05.src.tar.gz
WRKSRC=		${WRKDIR}/FElt-3.05
NO_CONFIGURE=	YES
EVAL_PREFIX+=	RL_PREFIX=readline
USE_X11=	YES
USE_XAW=	YES
XAW_TYPE=	3d

post-extract:
	@${GZCAT} ${DISTDIR}/felt-3.05.ps.gz > ${WRKSRC}/felt.ps

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/felt
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/felt
	${INSTALL_DATA} ${WRKSRC}/felt.ps ${PREFIX}/share/doc/felt
	@for i in FAQ FAQ.html README README.old COPYING CHANGELOG TODO; do \
	${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/felt;		    \
	done
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/felt

.include "../../mk/bsd.pkg.mk"
