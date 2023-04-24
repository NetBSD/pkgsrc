# $NetBSD: Makefile,v 1.1 2023/04/24 13:04:48 riastradh Exp $

DISTNAME=	seadata-small
PKGNAME=	pari-${DISTNAME}-0.0a20090618
CATEGORIES=	math
MASTER_SITES=	https://pari.math.u-bordeaux.fr/pub/pari/packages/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pari.math.u-bordeaux.fr/
COMMENT=	Schoof/Atkins/Elkies data for pari
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	pari-seadata-[0-9]*
CONFLICTS+=	pari-seadata-big-[0-9]*

DEPENDS+=	pari>=2.4.3:../../math/pari

WRKSRC=		${WRKDIR}/data/seadata

DIST_SUBDIR=		${PKGNAME}
NO_BUILD=		yes
INSTALLATION_DIRS=	share/pari/seadata

do-install:
	${INSTALL_DATA} ${WRKSRC}/* ${DESTDIR}${PREFIX}/share/pari/seadata

.include "../../mk/bsd.pkg.mk"
