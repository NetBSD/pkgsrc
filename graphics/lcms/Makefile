# $NetBSD: Makefile,v 1.5 2002/09/01 15:15:37 kim Exp $
# FreeBSD: ports/graphics/lcms/Makefile,v 1.2 2000/12/19 15:36:26 sobomax Exp

DISTNAME=	lcms-1.06
CATEGORIES=	graphics
MASTER_SITES=	http://www.littlecms.com/ \
		http://www.abaforum.es/martim/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.littlecms.com/
COMMENT=	Light Color Management System -- a color management library

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lcms
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/doc
	cd ${WRKSRC}/doc && ${PAX} -rw . ${PREFIX}/share/doc/lcms

.include "../../mk/bsd.pkg.mk"
