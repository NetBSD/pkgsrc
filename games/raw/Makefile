# $NetBSD: Makefile,v 1.1.1.1 2004/05/14 15:42:14 dillo Exp $
#

DISTNAME=		raw-0.1.0
CATEGORIES=		games
MASTER_SITES=		http://membres.lycos.fr/cyxdown/raw/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://membres.lycos.fr/cyxdown/raw/
COMMENT=		Engine for playing Another World

USE_BUILDLINK3=		yes
ALL_TARGET=		raw

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DSYS_BIG_ENDIAN
.elif ${MACHINE_ENDIAN} == "little"
CFLAGS+=	-DSYS_LITTLE_ENDIAN
.else
BROKEN=       "Unknown endianness"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/raw ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/raw
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/raw

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
