# $NetBSD: Makefile,v 1.5 2001/06/20 07:28:09 jlam Exp $
#

DISTNAME=		libiconv-1.6.1
CATEGORIES=		converters
MASTER_SITES=		ftp://ftp.ilog.fr/pub/Users/haible/gnu/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://clisp.cons.org/~haible/packages-libiconv.html
COMMENT=		character set conversion library

USE_BUILDLINK_ONLY=	YES
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
