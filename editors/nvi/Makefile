# $NetBSD: Makefile,v 1.6 2003/03/29 12:40:45 jmmv Exp $
#

DISTNAME=	nvi-1.81.5
WRKSRC=		${WRKDIR}/${DISTNAME}/build.unix
CATEGORIES=	editors
MASTER_SITES=	http://www.kotnet.org/~skimo/nvi/devel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://www.kotnet.org/~skimo/nvi/devel/
COMMENT=	Berkeley nvi with additional features

GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--with-db3=${BUILDLINK_PREFIX.db3}
CONFIGURE_ARGS+=	--program-transform-name='s,^,n,'
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

USE_BUILDLINK2=		YES

.include "../../databases/db3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
