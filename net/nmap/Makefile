# $NetBSD: Makefile,v 1.30 2003/11/12 03:39:41 jschauma Exp $
#

DISTNAME=	nmap-3.48
PKGREVISION=	1
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
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.libpcre}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--without-nmapfe

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
MAKE_ENV+=	CPPFLAGS=""
.endif

.include "../../devel/pcre/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
