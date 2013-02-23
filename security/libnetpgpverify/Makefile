# $NetBSD: Makefile,v 1.1.1.1 2013/02/23 21:04:26 agc Exp $

DISTNAME=	libnetpgpverify-${VERSION}
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	PGP signature verification library
LICENSE=	modified-bsd

USE_LIBTOOL=	yes
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

VERSION!=	${AWK} '/\#define.*NETPGP_VERIFY_H_/ {print $$3}' ${FILESDIR}/src/libverify/verify.h

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	libtool --mode=install ${INSTALL_LIB} ${WRKSRC}/libnetpgpverify.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/libverify/verify.h ${DESTDIR}${PREFIX}/include/netpgp
	${INSTALL_DATA} ${WRKSRC}/src/libverify/libnetpgpverify.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
