# $NetBSD: Makefile,v 1.3.2.1 2002/06/23 18:45:18 jlam Exp $
#

DISTNAME=	nvi-1.81.5
CATEGORIES=	editors
MASTER_SITES=	http://www.kotnet.org/~skimo/nvi/devel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://www.kotnet.org/~skimo/nvi/devel/
COMMENT=	Berkeley nvi with additional features

GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS+=	--with-db3=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--program-transform-name='s,^,n,'
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

USE_BUILDLINK_ONLY=	YES

WRKSRC=			${WRKDIR}/${DISTNAME}/build.unix

.include "../../databases/db3/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
