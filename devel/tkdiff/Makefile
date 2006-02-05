# $NetBSD: Makefile,v 1.17 2006/02/05 23:08:54 joerg Exp $
#

DISTNAME=	tkdiff
PKGNAME=	${DISTNAME}-4.0.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tkdiff/}
EXTRACT_SUFX=	.zip

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/tkdiff/
COMMENT=	Graphical 2-way diff/merge tool

DEPENDS+=	tk>=8.3.2:../../x11/tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=	${PKGNAME_NOREV}
NO_BUILD=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tkdiff ${PREFIX}/bin/tkdiff4

.include "../../mk/bsd.pkg.mk"
