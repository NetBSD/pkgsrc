# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:49 tv Exp $
#

DISTNAME=		cambevao-2.0
PKGREVISION=	1
CATEGORIES=		graphics
MASTER_SITES=		http://core.de/~coto/projects/cambevao/

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://core.de/~coto/projects/cambevao/
COMMENT=		Grabs images as jpg from bktr and ov511+ based USB webcams

USE_BUILDLINK3=		yes
MAKE_ENV=		prefix=${PREFIX}
RCD_SCRIPTS=		cambevao
USE_PKGINSTALL=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-*

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cambevao
	${INSTALL_DATA} ${WRKSRC}/cambevao.xml ${PREFIX}/share/examples/cambevao
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cambevao.README
	${INSTALL_SCRIPT} ${WRKSRC}/cambevao.rc.d ${RCD_SCRIPTS_EXAMPLEDIR}/cambevao

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
