# $NetBSD: Makefile,v 1.1 2013/01/23 21:53:39 wiz Exp $
#

DISTNAME=	high-pass
PKGNAME=	gimp-${DISTNAME}-filter-1.2
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/
EXTRACT_SUFX=	.scm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://registry.gimp.org/node/7385
COMMENT=	General purpose high-pass filter plugin for GIMP
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/high-pass.scm
USE_LANGUAGES=	# none

DEPENDS+=	gimp>=2.0:../../graphics/gimp

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	share/gimp/2.0/scripts

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${PREFIX}/share/gimp/2.0/scripts

.include "../../mk/bsd.pkg.mk"
