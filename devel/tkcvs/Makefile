# $NetBSD: Makefile,v 1.23 2002/01/28 16:55:53 wiz Exp $
#

DISTNAME=	tkcvs-7_03
PKGNAME=	tkcvs-7.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.twobarleycorns.net/ \
		${MASTER_SITE_SOURCEFORGE:=tkcvs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.twobarleycorns.net/tkcvs.html
COMMENT=	Tcl/Tk frontends to CVS and diff

USE_BUILDLINK_ONLY=	YES
NO_BUILD=		YES

do-install:
	(cd ${WRKSRC} && ./doinstall.tcl ${PREFIX})

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tkcvs
	${INSTALL_DATA} ${WRKSRC}/README.tkcvs ${PREFIX}/share/doc/tkcvs/

.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
