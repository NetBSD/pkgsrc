# $NetBSD: Makefile,v 1.9 2004/01/03 18:49:35 reed Exp $
#

DISTNAME=	xchiplogo
PKGNAME=	xchiplogo-19991222
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://www.eleceng.adelaide.edu.au/Personal/moini/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.eleceng.adelaide.edu.au/Personal/moini/chiplogo.html
COMMENT=	Program for generating pretty logos on VLSI chips

USE_BUILDLINK2=	YES
USE_X11=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xchiplogo ${LOCALBASE}/bin/xchiplogo

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xforms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
