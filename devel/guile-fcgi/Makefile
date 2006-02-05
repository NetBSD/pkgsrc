# $NetBSD: Makefile,v 1.13 2006/02/05 23:08:43 joerg Exp $

DISTNAME=	guile-fcgi-0.1
PKGREVISION=	6
CATEGORIES=	devel www
MASTER_SITES=	http://www.bgu.ru/%7Edsa/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.bgu.ru/%7Edsa/guilefcgi.html
COMMENT=	Guile interface to FastCGI

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--with-fcgi-includes=${BUILDLINK_PREFIX.fcgi}/include
CONFIGURE_ARGS+=--with-fcgi-lib=${BUILDLINK_PREFIX.fcgi}/lib

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} guile-fcgi.x
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${BUILD_TARGET}

.include "../../lang/guile14/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
