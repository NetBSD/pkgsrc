# $NetBSD: Makefile,v 1.8 2004/01/24 00:56:37 jlam Exp $
# FreeBSD: ports/graphics/lcms/Makefile,v 1.2 2000/12/19 15:36:26 sobomax Exp

DISTNAME=	lcms-1.06
CATEGORIES=	graphics
MASTER_SITES=	http://www.littlecms.com/ \
		http://www.abaforum.es/martim/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.littlecms.com/
COMMENT=	Light Color Management System -- a color management library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lcms
	cd ${WRKSRC}/doc && ${PAX} -rw . ${PREFIX}/share/doc/lcms
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/lcms

.include "../../mk/bsd.pkg.mk"
