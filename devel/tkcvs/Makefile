# $NetBSD: Makefile,v 1.19 2001/02/28 12:29:29 wiz Exp $
#

DISTNAME=	tkcvs-6.4
CATEGORIES=	devel
MASTER_SITES=	http://www.twobarleycorns.net/ \
		${MASTER_SITE_SOURCEFORGE:=tkcvs/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.twobarleycorns.net/tkcvs.html
COMMENT=	Tcl/Tk frontends to CVS and diff

DEPENDS+=	tk>=8.1:../../x11/tk

NO_BUILD=	yes

post-extract:
	${MV} ${WRKSRC}/tkcvs/tkcvs.n ${WRKSRC}/tkcvs/tkcvs.1

do-install:
	(cd ${WRKSRC} && ./doinstall.tcl ${PREFIX})

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tkcvs
	${INSTALL_DATA} ${WRKSRC}/README.tkcvs ${PREFIX}/share/doc/tkcvs/

.include "../../mk/bsd.pkg.mk"
