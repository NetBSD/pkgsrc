# $NetBSD: Makefile,v 1.19 2020/01/26 17:31:55 rillig Exp $
#

DISTNAME=	scamper-cvs-20141211d
PKGNAME=	${DISTNAME:S/-cvs//}
CATEGORIES=	net
MASTER_SITES=	http://www.caida.org/tools/measurement/scamper/code/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	https://www.caida.org/tools/measurement/scamper/
COMMENT=	Tool for parallelised IPv4 and IPv6 measurement
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_FEATURES+=	inet6

.include "../../mk/bsd.pkg.mk"
