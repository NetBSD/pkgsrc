# $NetBSD: Makefile,v 1.22 2001/10/21 10:02:03 wiz Exp $
#

DISTNAME=	tkcvs-7.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.twobarleycorns.net/ \
		${MASTER_SITE_SOURCEFORGE:=tkcvs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.twobarleycorns.net/tkcvs.html
COMMENT=	Tcl/Tk frontends to CVS and diff

USE_BUILDLINK_ONLY=	YES
NO_BUILD=		YES

post-extract:
	${MV} ${WRKSRC}/tkcvs/tkcvs.n ${WRKSRC}/tkcvs/tkcvs.1

do-install:
	(cd ${WRKSRC} && ./doinstall.tcl ${PREFIX})

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tkcvs
	${INSTALL_DATA} ${WRKSRC}/README.tkcvs ${PREFIX}/share/doc/tkcvs/

.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
