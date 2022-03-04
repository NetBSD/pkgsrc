# $NetBSD: Makefile,v 1.4 2022/03/04 18:51:47 jperkin Exp $

DISTNAME=	dcfldd-1.3.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dcfldd/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://dcfldd.sourceforge.net/
COMMENT=	Enhanced version of GNU dd with features useful for forensics
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t
# Obviously x86-specific, if you want to support SPARC add the necessary logic.
CFLAGS.SunOS+=	-DLITTLE_ENDIAN=1234 -DBYTE_ORDER=LITTLE_ENDIAN

.include "../../mk/bsd.pkg.mk"
