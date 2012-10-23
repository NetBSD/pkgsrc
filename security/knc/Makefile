# $NetBSD: Makefile,v 1.6 2012/10/23 13:02:08 schmonz Exp $
#

DISTNAME=		knc-1.7
CATEGORIES=		security net
MASTER_SITES=		http://oskt.secure-endpoints.com/downloads/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://oskt.secure-endpoints.com/knc.html
COMMENT=		Kerberised NetCat
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
