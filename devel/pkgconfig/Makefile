# $NetBSD: Makefile,v 1.1.1.1 2001/08/11 14:15:37 rh Exp $
#

DISTNAME=	pkgconfig-0.8.0
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.freedesktop.org/software/pkgconfig/
COMMENT=	system for managing library compile/link flags

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

post-configure:
	${RM} -f ${WRKSRC}/libtool
	${LN} -s ${LOCALBASE}/bin/libtool ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
