# $NetBSD: Makefile,v 1.27 2003/07/17 22:51:28 grant Exp $
#

DISTNAME=	nmap-3.30
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.insecure.org/nmap/
COMMENT=	Network/port scanner with OS detection

USE_BUILDLINK2=	YES
USE_GCC_SHLIB=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--without-nmapfe

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
MAKE_ENV+=	CPPFLAGS=""
.endif

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
