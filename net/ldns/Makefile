# $NetBSD: Makefile,v 1.3 2008/08/19 12:59:40 joerg Exp $

DISTNAME=	ldns-1.3.0
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/drill/
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/ldns/

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/projects/ldns/
COMMENT=	Library for simplified DNS programming

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

REPLACE_PERL=	doc/doxyparse.pl

.include "../../mk/bsd.pkg.mk"
