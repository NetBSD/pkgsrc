# $NetBSD: Makefile,v 1.8 2013/02/14 19:48:04 schmonz Exp $
#

DISTNAME=		knc-1.7.1
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
