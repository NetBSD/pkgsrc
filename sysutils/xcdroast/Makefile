# $NetBSD: Makefile,v 1.3 2001/02/17 17:42:22 wiz Exp $

DISTNAME=	xcdroast-0.98alpha8
PKGNAME=	xcdroast-0.98a8
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.xcdroast.org/
COMMENT=	graphical user interface for the command-line cdrecord-tools

DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	cdrecord-1.9nb1:../../sysutils/cdrecord

USE_X11=	YES

post-patch:
	${MV} -f ${WRKSRC}/xcdroast.h ${WRKSRC}/xcdroast.h.bak
	${SED}  -e "s,@@PREFIX@@,${PREFIX},g" \
		< ${WRKSRC}/xcdroast.h.bak > ${WRKSRC}/xcdroast.h

.include "../../mk/bsd.pkg.mk"
