# $NetBSD: Makefile,v 1.7 2002/04/24 02:56:15 dmcmahill Exp $
#

DISTNAME=		libiconv-1.7
CATEGORIES=		converters
MASTER_SITES=		ftp://ftp.ilog.fr/pub/Users/haible/gnu/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/libiconv/
COMMENT=		character set conversion library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libcharset/libtool

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
PLIST_SRC=		${PKGDIR}/PLIST.${OPSYS}
.endif

test: build
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE_PROGRAM} check |& tee ${WRKDIR}/check.log

.include "../../mk/bsd.pkg.mk"
