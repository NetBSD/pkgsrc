# $NetBSD: Makefile,v 1.13 2012/10/23 17:19:07 asau Exp $
#

DISTNAME=	scamper-cvs-20111202b
PKGNAME=	${DISTNAME:S/-cvs//}
CATEGORIES=	net
MASTER_SITES=	http://www.wand.net.nz/scamper/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://www.wand.net.nz/scamper/
COMMENT=	Tool for parallelised IPv4 and IPv6 measurement
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_FEATURES+=	inet6

.include "../../mk/bsd.pkg.mk"
