# $NetBSD: Makefile,v 1.24 2002/10/21 14:52:27 wiz Exp $
#

DISTNAME=	tkcvs-7_03
PKGNAME=	tkcvs-7.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.twobarleycorns.net/ \
		${MASTER_SITE_SOURCEFORGE:=tkcvs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.twobarleycorns.net/tkcvs.html
COMMENT=	Tcl/Tk frontends to CVS and diff

USE_BUILDLINK2=		YES
NO_BUILD=		YES

do-install:
	(cd ${WRKSRC} && ./doinstall.tcl ${PREFIX})

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tkcvs
	${INSTALL_DATA} ${WRKSRC}/README.tkcvs ${PREFIX}/share/doc/tkcvs/

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
