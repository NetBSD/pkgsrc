# $NetBSD: Makefile,v 1.4 2003/05/02 11:54:30 wiz Exp $

DISTNAME=	guile-fcgi-0.1
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://www.bgu.ru/%7Edsa/

MAINTAINER=	epg@pretzelnet.org
HOMEPAGE=	http://www.bgu.ru/%7Edsa/guilefcgi.html
COMMENT=	Guile interface to FastCGI

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

#CONFIGURE_ARGS+=	--with-fcgi-includes=${PREFIX}/include

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} guile-fcgi.x
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

.include "../../lang/guile14/buildlink2.mk"
.include "../../www/fcgi/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
