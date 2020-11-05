# $NetBSD: Makefile,v 1.42 2020/11/05 09:08:21 ryoon Exp $

DISTNAME=	resynthesizer-0.16
PKGNAME=	gimp-${DISTNAME}
PKGREVISION=	39
CATEGORIES=	graphics
MASTER_SITES=	http://www.logarithmic.net/pfh-files/resynthesizer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logarithmic.net/pfh/resynthesizer
COMMENT=	Gimp plug-in for texture synthesis
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	lib/gimp/2.0/plug-ins
INSTALLATION_DIRS+=	share/gimp/2.0/scripts
INSTALLATION_DIRS+=	share/doc/gimp-resynthesizer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/resynth \
		${DESTDIR}${PREFIX}/lib/gimp/2.0/plug-ins/
	${INSTALL_DATA} ${WRKSRC}/smart-enlarge.scm \
		${DESTDIR}${PREFIX}/share/gimp/2.0/scripts/
	${INSTALL_DATA} ${WRKSRC}/smart-remove.scm \
		${DESTDIR}${PREFIX}/share/gimp/2.0/scripts/
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/gimp-resynthesizer

.include "../../graphics/gimp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
