# $NetBSD: Makefile,v 1.10 2011/04/30 11:35:26 obache Exp $
#

DISTNAME=	scamper-cvs-20110421
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
