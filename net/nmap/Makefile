# $NetBSD: Makefile,v 1.39 2004/11/13 22:04:53 jlam Exp $
#

DISTNAME=	nmap-3.75
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.insecure.org/nmap/
COMMENT=	Network/port scanner with OS detection

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-libpcre=${BUILDLINK_PREFIX.libpcre}
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--without-nmapfe

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
MAKE_ENV+=	CPPFLAGS=""
.endif

.include "../../devel/pcre/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
