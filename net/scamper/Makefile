# $NetBSD: Makefile,v 1.12 2012/04/16 06:09:47 markd Exp $
#

DISTNAME=	scamper-cvs-20111202b
PKGNAME=	${DISTNAME:S/-cvs//}
CATEGORIES=	net
MASTER_SITES=	http://www.wand.net.nz/scamper/

MAINTAINER=	mjl@luckie.org.nz
HOMEPAGE=	http://www.wand.net.nz/scamper/
COMMENT=	Tool for parallelised IPv4 and IPv6 measurement
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_FEATURES+=	inet6

.include "../../mk/bsd.pkg.mk"
