# $NetBSD: Makefile,v 1.2 2020/01/18 23:35:09 rillig Exp $

DISTNAME=	libmultigest-${VERSION}
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://www.NetBSD.org/
COMMENT=	Multiple, concatenated digest value calculation library
LICENSE=	modified-bsd

FILESDIR=	${.CURDIR}/../../security/multigest/files

GNU_CONFIGURE=	yes
.if !defined(BOOTSTRAP)
USE_LIBTOOL=	yes
.endif
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} '/\#define.*MULTIGEST_H_/ {print $$3}' ${FILESDIR}/multigest.h

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}
.if defined(BOOTSTRAP)
	cd ${WRKSRC} && ${CP} Makefile.lib.in Makefile.in
.else
	cd ${WRKSRC} && ${CP} Makefile.libtool.in Makefile.in
.endif

.include "../../mk/bsd.pkg.mk"
