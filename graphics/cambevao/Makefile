# $NetBSD: Makefile,v 1.23 2017/08/01 16:47:39 wiz Exp $
#

DISTNAME=		cambevao-2.2
PKGREVISION=		7
CATEGORIES=		graphics
#MASTER_SITES=		http://coto.marsrakete.de/projects/cambevao/

MAINTAINER=		abs@NetBSD.org
#HOMEPAGE=		http://coto.marsrakete.de/projects/cambevao/
COMMENT=		Grabs jpg images from bktr and ov511+ based USB webcams
LICENSE=		modified-bsd AND original-bsd

MAKE_ENV+=		prefix=${PREFIX:Q}
MAKE_FLAGS+=		INSTALL=${INSTALL_PROGRAM:Q}
RCD_SCRIPTS=		cambevao
RCD_SCRIPT_SRC.cambevao=	${WRKSRC}/cambevao.rc.d

INSTALLATION_DIRS=	bin share/examples/cambevao share/examples/rc.d

ONLY_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* DragonFly-*-*

INSTALLATION_DIRS+=	${PREFIX}/share/examples/cambevao
INSTALLATION_DIRS+=	${PREFIX}/share/doc

MAKE_FLAGS+=		EXPAT_PATH=${BUILDLINK_PREFIX.expat}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cambevao ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cambevao.xml ${DESTDIR}${PREFIX}/share/examples/cambevao
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cambevao.README

.include "../../mk/jpeg.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
