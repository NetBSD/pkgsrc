# $NetBSD: Makefile,v 1.2 2014/02/16 17:15:48 agc Exp $

DISTNAME=	libnetpgpverify-${VERSION}
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	PGP and ssh signature verification library
LICENSE=	modified-bsd

FILESDIR=	${.CURDIR}/../netpgpverify/files

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} '/\#define.*NETPGP_VERIFY_H_/ {print $$3}' ${FILESDIR}/verify.h

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}
.if defined(BOOTSTRAP)
	cd ${WRKSRC} && ${CP} Makefile.lib.in Makefile.in
.else
	cd ${WRKSRC} && ${CP} Makefile.libtool.in Makefile.in
.endif

.include "../../mk/bsd.pkg.mk"
