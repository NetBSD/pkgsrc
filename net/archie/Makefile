# $NetBSD: Makefile,v 1.11 2003/09/22 16:24:27 wiz Exp $
# FreeBSD Id: Makefile,v 1.7 1997/07/21 00:04:13 fenner Exp
#

DISTNAME=	c-archie-1.4.1-FIXED
PKGNAME=	archie-1.4.1
WRKSRC=		${WRKDIR}/archie-1.4.1-FIX
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.uni-stuttgart.de/pub/unix/comm/infosystems/archie/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.bunyip.com/products/archie/
COMMENT=	Prospero client for the archie service

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD}
LDFLAGS+=	-lcompat
.elif ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl
.endif

.include "../../mk/bsd.pkg.mk"
