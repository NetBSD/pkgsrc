# $NetBSD: Makefile,v 1.9 2006/01/24 07:32:10 wiz Exp $
#

DISTNAME=		cambevao-2.2
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		http://core.de/~coto/projects/cambevao/

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://core.de/~coto/projects/cambevao/
COMMENT=		Grabs images as jpg from bktr and ov511+ based USB webcams

MAKE_ENV+=		prefix=${PREFIX:Q}
RCD_SCRIPTS=		cambevao

ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-*

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cambevao
	${INSTALL_DATA} ${WRKSRC}/cambevao.xml ${PREFIX}/share/examples/cambevao
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cambevao.README
	${INSTALL_SCRIPT} ${WRKSRC}/cambevao.rc.d ${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}/cambevao

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
