# $NetBSD: Makefile,v 1.16 2014/11/16 05:17:24 markd Exp $
#

DISTNAME=	scamper-cvs-20141101
PKGNAME=	${DISTNAME:S/-cvs//}
CATEGORIES=	net
MASTER_SITES=	http://www.caida.org/tools/measurement/scamper/code/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://www.caida.org/tools/measurement/scamper/
COMMENT=	Tool for parallelised IPv4 and IPv6 measurement
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_FEATURES+=	inet6

.include "../../mk/bsd.pkg.mk"
