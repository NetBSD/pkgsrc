# $NetBSD: Makefile,v 1.6 2002/03/13 17:37:45 fredb Exp $

DISTNAME=	xcdroast-0.98alpha9
PKGNAME=	xcdroast-0.98a9
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xcdroast/}

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.xcdroast.org/
COMMENT=	graphical user interface for the command-line cdrecord-tools

eEPENDS+=	imlib>=1.9.11nb1:../../graphics/imlib
DEPENDS+=	cdrecord-1.10:../../sysutils/cdrecord

USE_X11=	YES

post-patch:
	${MV} -f ${WRKSRC}/xcdroast.h ${WRKSRC}/xcdroast.h.bak
	${SED}  -e "s,@@PREFIX@@,${PREFIX},g" \
		< ${WRKSRC}/xcdroast.h.bak > ${WRKSRC}/xcdroast.h

.include "../../mk/bsd.pkg.mk"
