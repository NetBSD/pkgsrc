# $NetBSD: Makefile,v 1.3 2004/10/11 22:14:52 reed Exp $
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
	${INSTALL_SCRIPT} ${WRKSRC}/cambevao.rc.d ${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}/cambevao

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
