# $NetBSD: Makefile,v 1.2 2001/02/12 19:24:39 tron Exp $
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

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
PLIST_SRC=		${PKGDIR}/PLIST.${OPSYS}
.endif

.include "../../mk/bsd.pkg.mk"
