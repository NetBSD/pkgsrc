# $NetBSD: Makefile,v 1.13 2007/03/24 19:21:25 joerg Exp $
#

DISTNAME=		cambevao-2.2
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		http://core.de/~coto/projects/cambevao/

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		http://core.de/~coto/projects/cambevao/
COMMENT=		Grabs images as jpg from bktr and ov511+ based USB webcams

MAKE_ENV+=		prefix=${PREFIX:Q}
MAKE_FLAGS+=		INSTALL=${INSTALL_PROGRAM:Q}
RCD_SCRIPTS=		cambevao

INSTALLATION_DIRS=	bin share/examples/cambevao share/examples/rc.d

ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* DragonFly-*-*

post-install:
	${INSTALL_DATA} ${WRKSRC}/cambevao.xml ${PREFIX}/share/examples/cambevao
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cambevao.README
	${INSTALL_SCRIPT} ${WRKSRC}/cambevao.rc.d ${PREFIX}/${RCD_SCRIPTS_EXAMPLEDIR}/cambevao

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
