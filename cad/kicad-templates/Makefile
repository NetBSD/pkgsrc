# $NetBSD: Makefile,v 1.3 2020/01/26 17:30:48 rillig Exp $
#

V=		5.1.4
DISTNAME=	kicad-templates-${V}
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=KiCad/}
GITHUB_TAG=	${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kicad-pcb.org/
COMMENT=	Project templates for the schematic CAD software
LICENSE=	cc-by-sa-v4.0

USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
