# $NetBSD: Makefile,v 1.6 2001/04/30 20:56:51 jtb Exp $

DISTNAME=	felt-3.05.src
PKGNAME=	felt-3.05
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/FElt/
DISTFILES=	felt-3.05.src.tar.gz felt-3.05.ps.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://felt.sourceforge.net/
COMMENT=	Free system for introductory level finite element analysis

DEPENDS+=	readline-[0-9]*:../../devel/readline

EXTRACT_ONLY=	felt-3.05.src.tar.gz
WRKSRC=		${WRKDIR}/FElt-3.05
NO_CONFIGURE=	# defined
EVAL_PREFIX+=	RL_PREFIX=readline
USE_X11BASE=	yes
USE_XAW=	yes
XAW_TYPE=	3d

post-extract:
	@${GZCAT} ${DISTDIR}/felt-3.05.ps.gz > ${WRKSRC}/felt.ps

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/felt
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/felt
	${INSTALL_DATA} ${WRKSRC}/felt.ps ${PREFIX}/share/doc/felt
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ FAQ.html README README.old	\
		COPYING CHANGELOG TODO ${PREFIX}/share/doc/felt
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/felt

.include "../../mk/bsd.pkg.mk"
