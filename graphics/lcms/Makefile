# $NetBSD: Makefile,v 1.1.1.1 2001/03/07 08:22:52 skrll Exp $
# FreeBSD: ports/graphics/lcms/Makefile,v 1.2 2000/12/19 15:36:26 sobomax Exp

DISTNAME=	lcms-1.06
CATEGORIES=	graphics
MASTER_SITES=	http://www.littlecms.com/ \
		http://www.abaforum.es/martim/

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.littlecms.com/
COMMENT=	"Light Color Management System -- a color management library"

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lcms
	${CP} -rp ${WRKSRC}/doc/* ${PREFIX}/share/doc/lcms/

.include "../../mk/bsd.pkg.mk"
