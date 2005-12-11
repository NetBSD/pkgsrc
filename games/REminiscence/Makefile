# $NetBSD: Makefile,v 1.3 2005/12/11 09:40:40 wiz Exp $
#

DISTNAME=		REminiscence-0.1.6
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://membres.lycos.fr/cyxdown/reminiscence/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://membres.lycos.fr/cyxdown/reminiscence/
COMMENT=		Engine to play Flashback by Delphine Software

BUILD_TARGET=		rs
MAKE_ENV+=		DEFINES=${DEFINES:Q}

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
DEFINES+=        -DSYS_BIG_ENDIAN
.elif ${MACHINE_ENDIAN} == "little"
DEFINES+=        -DSYS_LITTLE_ENDIAN
.else
BROKEN=       "Unknown endianness"
.endif

.include "../../devel/SDL/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rs ${LOCALBASE}/bin
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/REminiscence
	${INSTALL_DATA} ${WRKSRC}/README ${LOCALBASE}/share/doc/REminiscence

.include "../../mk/bsd.pkg.mk"
