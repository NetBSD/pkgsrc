# $NetBSD: Makefile,v 1.3 2017/07/30 22:32:20 wiz Exp $

DISTNAME=	HElib-20130501
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.zip

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/shaih/HElib/
COMMENT=	Homeomorphic Encryption library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/HElib-master/src

USE_LANGUAGES+=	c++
USE_TOOLS+=	gmake

TEST_TARGET=	check

AUTO_MKDIRS=	yes

pre-patch:
	for f in ${WRKSRC}/Makefile ${WRKSRC}/NumbTh.h; do	\
		${TR} -d '\r' < $${f} > $${f}.new;		\
		${MV} $${f}.new $${f};				\
	done

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/ntl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
