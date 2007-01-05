# $NetBSD: Makefile,v 1.1.6.1 2007/01/05 15:15:17 salo Exp $
#

DISTNAME=		partlibrary-2.0.1.2-1
PKGNAME=		qcad-partlibrary-2.0.1.2
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		http://www.ribbonsoft.com/archives/partlibrary/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ribbonsoft.com/qcad/
COMMENT=	About 4500 mech, elec, etc. parts for the QCad 2D CAD system

NO_CONFIGURE=	yes
NO_BUILD=	yes

DEPENDS+=	qcad>=2.0.0.0:../../cad/qcad

post-extract:
	chmod -R go-w ${WRKSRC}
	cd ${WRKSRC}/electrical/denzuq && chmod -x */*/*.dxf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/qcad/library
	cd ${WRKSRC} && pax -rwpm . ${PREFIX}/share/qcad/library

.include "../../mk/bsd.pkg.mk"
