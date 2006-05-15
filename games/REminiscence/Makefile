# $NetBSD: Makefile,v 1.6 2006/05/15 20:10:57 joerg Exp $
#

DISTNAME=		REminiscence-0.1.6
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://membres.lycos.fr/cyxdown/reminiscence/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://membres.lycos.fr/cyxdown/reminiscence/
COMMENT=		Engine to play Flashback by Delphine Software

USE_LANGUAGES=		c++

BUILD_TARGET=		rs
MAKE_ENV+=		DEFINES=${DEFINES:Q}

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
DEFINES+=        -DSYS_BIG_ENDIAN
.elif ${MACHINE_ENDIAN} == "little"
DEFINES+=        -DSYS_LITTLE_ENDIAN
.else
PKG_FAIL_REASON+=	"Unknown endianness."
.endif

.include "../../devel/SDL/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rs ${LOCALBASE}/bin
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/REminiscence
	${INSTALL_DATA} ${WRKSRC}/README ${LOCALBASE}/share/doc/REminiscence

.include "../../mk/bsd.pkg.mk"
