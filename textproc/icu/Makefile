# $NetBSD: Makefile,v 1.8 2002/10/28 22:49:15 seb Exp $
#

DISTNAME=	icu-1.7
CATEGORIES=	textproc
MASTER_SITES=	http://oss.software.ibm.com/icu/download/1.7/
EXTRACT_SUFX=	.tgz

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://oss.software.ibm.com/icu
COMMENT=	Robust and full-featured unicode support

WRKSRC=		${WRKDIR}/icu/source
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_BUILDLINK2=	YES

.include "../../mk/endian.mk"

BIG_ENDIAN=
LITTLE_ENDIAN=
.if ${MACHINE_ENDIAN} == "little"
BIG_ENDIAN=	'@comment '
.elif ${MACHINE_ENDIAN} == "big"
LITTLE_ENDIAN=	'@comment '
.endif
PLIST_SUBST+=	BIG_ENDIAN=${BIG_ENDIAN}
PLIST_SUBST+=	LITTLE_ENDIAN=${LITTLE_ENDIAN}

CONFIGURE_ARGS+= --disable-threads

pre-configure:
	${CHMOD} u+rx ${WRKSRC}/configure

test: build
	cd ${WRKSRC} && ${MAKE_PROGRAM} check

.include "../../mk/bsd.pkg.mk"
