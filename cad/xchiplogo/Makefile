# $NetBSD: Makefile,v 1.32 2025/09/21 21:22:39 wiz Exp $
#

DISTNAME=	xchiplogo
PKGNAME=	xchiplogo-19991222
PKGREVISION=	14
CATEGORIES=	cad
MASTER_SITES=	#http://www.eleceng.adelaide.edu.au/Personal/moini/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.eleceng.adelaide.edu.au/Personal/moini/chiplogo.html
COMMENT=	Program for generating pretty logos on VLSI chips

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xchiplogo ${DESTDIR}${PREFIX}/bin/xchiplogo

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
