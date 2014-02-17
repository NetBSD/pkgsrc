# $NetBSD: Makefile,v 1.1.1.1 2014/02/17 20:40:48 bouyer Exp $
#

V=		20140214
DISTNAME=	kicad-doc-${V}
CATEGORIES=	cad
MASTER_SITES=	http://ftp.fr.NetBSD.org/~bouyer/kicad/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://iut-tice.ujf-grenoble.fr/kicad/
COMMENT=	Documentation for the schematic and PCB CAD software
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_CMAKE=		yes

.include "../../devel/cmake/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
