# $NetBSD: Makefile,v 1.4 2008/12/17 17:52:33 joerg Exp $

DISTNAME=	ldns-1.4.0
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
