# $NetBSD: Makefile,v 1.2 2000/08/23 23:14:22 tron Exp $
#

DISTNAME=	xchiplogo
PKGNAME=	xchiplogo-19991222
CATEGORIES=	cad
MASTER_SITES=	http://www.eleceng.adelaide.edu.au/Personal/moini/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.eleceng.adelaide.edu.au/Personal/moini/chiplogo.html

DEPENDS+=	xforms-*:../../x11/xforms

USE_X11=	YES
USE_XPM=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xchiplogo ${LOCALBASE}/bin/xchiplogo

.include "../../mk/bsd.pkg.mk"
