# $NetBSD: Makefile,v 1.3 2002/02/07 12:39:12 seb Exp $
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
LTCONFIG_OVERRIDE=	${WRKSRC}/../dist/ltconfig

USE_BUILDLINK_ONLY=	YES

WRKSRC=			${WRKDIR}/${DISTNAME}/build.unix

.include "../../databases/db3/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
