# $NetBSD: Makefile,v 1.13 2004/03/10 00:17:31 minskim Exp $
#

DISTNAME=	tkdiff
PKGNAME=	${DISTNAME}-4.0b2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkdiff/}
EXTRACT_SUFX=	.zip

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.accurev.com/free/tkdiff/index.html
COMMENT=	Graphical 2-way diff/merge tool

DEPENDS+=	tk>=8.3.2:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=	${PKGNAME_NOREV}
NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_BUILDLINK=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tkdiff ${PREFIX}/bin/tkdiff4

.include "../../mk/bsd.pkg.mk"
