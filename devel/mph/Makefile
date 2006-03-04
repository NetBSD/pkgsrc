# $NetBSD: Makefile,v 1.4 2006/03/04 21:29:18 jlam Exp $
#

DISTNAME=	mph-1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/devel/lang/c/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Minimal perfect hashing functionality

INSTALLATION_DIRS=	bin share/doc

do-install:
	for i in emitc mph mphm; do					\
		${INSTALL_PROGRAM} ${WRKSRC}/$$i ${PREFIX}/bin;		\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/mphminm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mph.doc ${PREFIX}/share/doc

.include "../../mk/bsd.pkg.mk"
