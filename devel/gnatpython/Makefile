# $NetBSD: Makefile,v 1.25 2023/08/14 05:24:08 wiz Exp $

DISTNAME=	gnatpython-${SNAPSHOT}
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forge.open-do.org/projects/gnatpython
COMMENT=	Python package used in Ada testsuites
LICENSE=	gnu-gpl-v3
SNAPSHOT=	20110912

EGG_NAME=	gnatpython-1.2

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 20110912

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
