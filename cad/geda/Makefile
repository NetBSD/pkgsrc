# $NetBSD: Makefile,v 1.17 2002/03/14 00:39:35 wiz Exp $
#

DISTNAME=	gEDA-${PKGVERSION}
CATEGORIES=	cad
PKGREVISION=	1
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Toolset for automating electronic design

DEPENDS+=	gschem>=${PKGVERSION}:../../cad/gschem
DEPENDS+=	gnetlist>=${PKGVERSION}:../../cad/gnetlist
DEPENDS+=	gsymcheck>=${PKGVERSION}:../../cad/gsymcheck
DEPENDS+=	geda-utils-${PKGVERSION}nb1:../../cad/geda-utils
DEPENDS+=	geda-docs-20010304:../../cad/geda-docs

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

PKGVERSION=	20010708

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
