# $NetBSD: Makefile,v 1.1.1.1 2001/01/01 17:29:20 rh Exp $
#

DISTNAME=		libiconv-1.5
CATEGORIES=		converters
MASTER_SITES=		ftp://ftp.ilog.fr/pub/Users/haible/gnu/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://clisp.cons.org/~haible/packages-libiconv.html

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/autoconf/ltconfig
LTCONFIG_OVERRIDE+=	${WRKSRC}/libcharset/autoconf/ltconfig

.include "../../mk/bsd.pkg.mk"
