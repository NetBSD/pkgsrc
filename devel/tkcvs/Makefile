# $NetBSD: Makefile,v 1.27 2003/07/17 21:34:09 grant Exp $
#

DISTNAME=	tkcvs_7_1_2
PKGNAME=	tkcvs-7.1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.twobarleycorns.net/ \
		${MASTER_SITE_SOURCEFORGE:=tkcvs/}

MAINTAINER=	tech-pkg@NetBSD.org
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
