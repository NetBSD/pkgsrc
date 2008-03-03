# $NetBSD: Makefile,v 1.5 2008/03/03 17:45:36 jlam Exp $
#

DISTNAME=	mph-1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/devel/lang/c/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Minimal perfect hashing functionality

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin share/doc

do-install:
	for i in emitc mph mphm; do \
		${INSTALL_PROGRAM} ${WRKSRC}/$$i ${DESTDIR]${PREFIX}/bin; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/mphminm ${DESTDIR]${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/mph.doc ${DESTDIR]${PREFIX}/share/doc

.include "../../mk/bsd.pkg.mk"
