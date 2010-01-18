# $NetBSD: Makefile,v 1.20 2010/01/18 09:58:40 wiz Exp $
#

DISTNAME=	xchiplogo
PKGNAME=	xchiplogo-19991222
PKGREVISION=	7
CATEGORIES=	cad
MASTER_SITES=	http://www.eleceng.adelaide.edu.au/Personal/moini/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.eleceng.adelaide.edu.au/Personal/moini/chiplogo.html
COMMENT=	Program for generating pretty logos on VLSI chips

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xchiplogo ${DESTDIR}${PREFIX}/bin/xchiplogo

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
