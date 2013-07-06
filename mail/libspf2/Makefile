# $NetBSD: Makefile,v 1.11 2013/07/06 11:09:26 tron Exp $

DISTNAME=	libspf2-1.2.10
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf2.org/spf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libspf2.org/
COMMENT=	Implementation of the Sender Policy Framework
LICENSE=	modified-bsd OR gnu-lgpl-v2.1

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

CONFLICTS+=	libspf_alt-[0-9]*
CONFLICTS+=	p5-Mail-SPF-[0-9]*

.include "../../mk/bsd.pkg.mk"
