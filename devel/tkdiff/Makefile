# $NetBSD: Makefile,v 1.11 2004/02/16 16:34:02 recht Exp $
#

DISTNAME=	tkdiff_3_09
PKGNAME=	tkdiff-3.09
CATEGORIES=	devel
MASTER_SITES=	http://www.accurev.com/ftp/free/tkdiff/
EXTRACT_SUFX=	.zip

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.accurev.com/free/tkdiff/
COMMENT=	Graphical 2-way diff/merge tool

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_BUILDLINK=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tkdiff.tcl ${LOCALBASE}/bin/tkdiff3

.include "../../mk/bsd.pkg.mk"
