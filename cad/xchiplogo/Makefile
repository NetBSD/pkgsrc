# $NetBSD: Makefile,v 1.5 2002/04/17 04:45:08 fredb Exp $
#

DISTNAME=	xchiplogo
PKGNAME=	xchiplogo-19991222
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.eleceng.adelaide.edu.au/Personal/moini/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.eleceng.adelaide.edu.au/Personal/moini/chiplogo.html
COMMENT=	Program for generating pretty logos on VLSI chips

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	xforms>=0.9999:../../x11/xforms

USE_X11=	YES
USE_XPM=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xchiplogo ${LOCALBASE}/bin/xchiplogo

.include "../../mk/bsd.pkg.mk"
