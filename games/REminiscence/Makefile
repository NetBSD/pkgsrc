# $NetBSD: Makefile,v 1.14 2015/02/09 20:22:55 snj Exp $

DISTNAME=		REminiscence-0.2.1
CATEGORIES=		games
MASTER_SITES=		http://cyxdown.free.fr/reminiscence/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cyxdown.free.fr/reminiscence/
COMMENT=		Engine to play Flashback by Delphine Software

LICENSE=		gnu-gpl-v3

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

INSTALLATION_DIRS=	bin share/doc/REminiscence

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rs ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/REminiscence

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
