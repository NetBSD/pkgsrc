# $NetBSD: Makefile,v 1.1.1.1 2008/07/22 08:32:33 he Exp $

DISTNAME=	ldns-1.3.0
VERSION=	1.0-pre3
PKGNAME=	drill-${VERSION}
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/drill/

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/dnssec/drill.html
COMMENT=	DNSSEC debugging tool a'la dig

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-ldns=${PREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}/drill

.include "../../net/ldns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
