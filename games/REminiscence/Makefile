# $NetBSD: Makefile,v 1.9 2008/03/04 06:59:03 jlam Exp $
#

DISTNAME=		REminiscence-0.1.6
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		http://cyxdown.free.fr/reminiscence/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://cyxdown.free.fr/reminiscence/
COMMENT=		Engine to play Flashback by Delphine Software

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_PROGRAM} ${WRKSRC}/rs ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/REminiscence
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/REminiscence

.include "../../mk/bsd.pkg.mk"
