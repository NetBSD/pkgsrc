# $NetBSD: Makefile,v 1.3 2001/02/16 13:46:31 wiz Exp $
#

DISTNAME=	xchiplogo
PKGNAME=	xchiplogo-19991222
CATEGORIES=	cad
MASTER_SITES=	http://www.eleceng.adelaide.edu.au/Personal/moini/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.eleceng.adelaide.edu.au/Personal/moini/chiplogo.html
COMMENT=	Program for generating pretty logos on VLSI chips

DEPENDS+=	xforms-*:../../x11/xforms

USE_X11=	YES
USE_XPM=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xchiplogo ${LOCALBASE}/bin/xchiplogo

.include "../../mk/bsd.pkg.mk"
