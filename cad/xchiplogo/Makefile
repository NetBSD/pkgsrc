# $NetBSD: Makefile,v 1.7 2002/12/28 21:22:54 jschauma Exp $
#

DISTNAME=	xchiplogo
PKGNAME=	xchiplogo-19991222
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.eleceng.adelaide.edu.au/Personal/moini/

MAINTAINER=	dmcmahill@netbsd.org
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
