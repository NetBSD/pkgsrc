# $NetBSD: Makefile,v 1.14 2001/02/17 18:19:17 wiz Exp $
#

DISTNAME=	nmap-2.53
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html
COMMENT=	Network/port scanner with OS detection

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	INSTALL=${INSTALL}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=""
DEPENDS+=	libpcap-0.4:../../net/libpcap
CONFIGURE_ARGS+=--with-libpcap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-libpcap
.endif

.include "../../mk/bsd.pkg.mk"
