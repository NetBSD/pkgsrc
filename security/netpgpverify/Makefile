# $NetBSD: Makefile,v 1.1.1.1 2013/02/23 21:11:56 agc Exp $

DISTNAME=		netpgpverify-20120928
CATEGORIES=		security
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		PGP signature verification library
LICENSE=		modified-bsd

USE_LIBTOOL=		yes
AUTO_MKDIRS=		yes

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	libtool --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/netpgpverify ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/netpgpverify/netpgpverify.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libnetpgpverify/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
