# $NetBSD: Makefile,v 1.11 2004/12/03 15:14:54 wiz Exp $

DISTNAME=	guile-fcgi-0.1
PKGREVISION=	5
CATEGORIES=	devel www
MASTER_SITES=	http://www.bgu.ru/%7Edsa/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.bgu.ru/%7Edsa/guilefcgi.html
COMMENT=	Guile interface to FastCGI

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--with-fcgi-includes=${BUILDLINK_PREFIX.fcgi}/include
CONFIGURE_ARGS+=--with-fcgi-lib=${BUILDLINK_PREFIX.fcgi}/lib

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} guile-fcgi.x
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${BUILD_TARGET}

.include "../../lang/guile14/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
