# $NetBSD: Makefile,v 1.8 2004/10/03 00:13:28 tv Exp $

DISTNAME=	guile-fcgi-0.1
PKGREVISION=	4
CATEGORIES=	devel www
MASTER_SITES=	http://www.bgu.ru/%7Edsa/

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	http://www.bgu.ru/%7Edsa/guilefcgi.html
COMMENT=	Guile interface to FastCGI

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--with-fcgi-includes=${BUILDLINK_PREFIX.fcgi}/include
CONFIGURE_ARGS+=--with-fcgi-lib=${BUILDLINK_PREFIX.fcgi}/lib

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} guile-fcgi.x
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

.include "../../lang/guile14/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
