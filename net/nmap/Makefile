# $NetBSD: Makefile,v 1.21 2003/04/27 11:42:13 salo Exp $
#

DISTNAME=	nmap-3.26
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/
COMMENT=	Network/port scanner with OS detection

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--without-nmapfe

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
MAKE_ENV+=	CPPFLAGS=""
.endif

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
