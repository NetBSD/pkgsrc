# $NetBSD: Makefile,v 1.25 2003/07/13 17:47:50 wiz Exp $
#

DISTNAME=	gEDA-${PKGVERSION}
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Toolset for automating electronic design

DEPENDS+=	gschem-${PKGVERSION}nb2:../../cad/gschem
DEPENDS+=	gnetlist-${PKGVERSION}nb3:../../cad/gnetlist
DEPENDS+=	gsymcheck-${PKGVERSION}nb2:../../cad/gsymcheck
DEPENDS+=	geda-utils-${PKGVERSION}nb2:../../cad/geda-utils
DEPENDS+=	geda-docs-${PKGVERSION}:../../cad/geda-docs

USE_X11BASE=	yes
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

PKGVERSION=	20030223

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
