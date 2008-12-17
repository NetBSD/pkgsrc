# $NetBSD: Makefile,v 1.2 2008/12/17 17:53:26 joerg Exp $

VERSION=	1.4.0
DISTNAME=	ldns-${VERSION}
PKGNAME=	drill-${VERSION}
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/drill/

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/dnssec/drill.html
COMMENT=	DNSSEC debugging tool a'la dig

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-ldns=${PREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}/drill

.include "../../net/ldns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
