# $NetBSD: Makefile,v 1.2 2001/02/11 12:23:29 tron Exp $

DISTNAME=	xcdroast-0.98alpha8
PKGNAME=	xcdroast-0.98a8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.xcdroast.org/

DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	cdrecord-1.9nb1:../../sysutils/cdrecord

USE_X11=	YES

post-patch:
	${MV} -f ${WRKSRC}/xcdroast.h ${WRKSRC}/xcdroast.h.bak
	${SED}  -e "s,@@PREFIX@@,${PREFIX},g" \
		< ${WRKSRC}/xcdroast.h.bak > ${WRKSRC}/xcdroast.h

.include "../../mk/bsd.pkg.mk"
