# $NetBSD: Makefile,v 1.12 2000/10/08 15:06:08 hubertf Exp $
#

DISTNAME=	nmap-2.53
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	INSTALL=${INSTALL}
CONFIGURE_ARGS+=--with-libpcap

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=""
.endif

.include "../../mk/bsd.pkg.mk"
