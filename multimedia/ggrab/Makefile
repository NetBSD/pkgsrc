# $NetBSD: Makefile,v 1.10 2023/07/16 14:04:03 wiz Exp $

DISTNAME=		ggrab-0.22a-linux
PKGNAME=		${DISTNAME:S/-linux//}
PKGREVISION=		1
CATEGORIES=		multimedia
#MASTER_SITES=		http://www.menzebach.de/ggrab/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.menzebach.de/ggrab/
COMMENT=		Server for recording video streams from dream dvb-receivers

USE_LANGUAGES=	c++
WRKSRC=		${WRKDIR}/ggrab-0.22a

# Override Makefile's attempt to override LDFLAGS and force
# static linking (and ignore paths).
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}

RCD_SCRIPTS=		sserver
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	bin ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ggrab ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sserver ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
