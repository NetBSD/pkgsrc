# $NetBSD: Makefile,v 1.8 2000/04/29 17:32:19 wiz Exp $
#

DISTNAME=	nmap-2.50
CATEGORIES=	net security
MASTER_SITES=	http://www.insecure.org/nmap/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	INSTALL=${INSTALL}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	CPPFLAGS=""
.endif

.include "../../mk/bsd.pkg.mk"
