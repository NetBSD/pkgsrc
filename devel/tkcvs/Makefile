# $NetBSD: Makefile,v 1.21 2001/09/14 22:24:16 wiz Exp $
#

DISTNAME=	tkcvs-7.0.1
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
