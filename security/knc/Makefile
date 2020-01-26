# $NetBSD: Makefile,v 1.12 2020/01/26 17:32:03 rillig Exp $
#

DISTNAME=		knc-1.7.1
CATEGORIES=		security net
MASTER_SITES=		http://oskt.secure-endpoints.com/downloads/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://oskt.secure-endpoints.com/knc.html
COMMENT=		Kerberised NetCat
LICENSE=		mit

GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl

.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
