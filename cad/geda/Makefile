# $NetBSD: Makefile,v 1.14 2001/02/16 13:46:19 wiz Exp $
#

DISTNAME=	gEDA-${PKGVERSION}
CATEGORIES=	cad
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Toolset for automating electronic design

DEPENDS+=	gschem-${PKGVERSION}:../../cad/gschem
DEPENDS+=	gnetlist-${PKGVERSION}:../../cad/gnetlist
DEPENDS+=	gsymcheck-${PKGVERSION}:../../cad/gsymcheck
DEPENDS+=	geda-utils-${PKGVERSION}:../../cad/geda-utils
DEPENDS+=	geda-docs-${PKGVERSION}:../../cad/geda-docs

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

PKGVERSION=	20000220

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
