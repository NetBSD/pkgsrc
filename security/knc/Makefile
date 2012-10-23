# $NetBSD: Makefile,v 1.7 2012/10/23 18:16:31 asau Exp $
#

DISTNAME=		knc-1.7
CATEGORIES=		security net
MASTER_SITES=		http://oskt.secure-endpoints.com/downloads/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://oskt.secure-endpoints.com/knc.html
COMMENT=		Kerberised NetCat
LICENSE=		mit

GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
