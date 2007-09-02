# $NetBSD: Makefile,v 1.14 2007/09/02 12:53:20 joerg Exp $
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
RCD_SCRIPT_SRC.cambevao=	${WRKSRC}/cambevao.rc.d

INSTALLATION_DIRS=	bin share/examples/cambevao share/examples/rc.d

ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* DragonFly-*-*

post-install:
	${INSTALL_DATA} ${WRKSRC}/cambevao.xml ${PREFIX}/share/examples/cambevao
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cambevao.README

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
