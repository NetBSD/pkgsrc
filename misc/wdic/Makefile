# $NetBSD: Makefile,v 1.1.1.1 2005/03/07 14:48:09 minskim Exp $
#

DISTNAME=		wdic_wob_v3.0
PKGNAME=		wdic-3.0
CATEGORIES=		misc
MASTER_SITES=		http://kldp.net/frs/download.php/1732/

MAINTAINER=		fox9@netb.co.kr
HOMEPAGE=		http://kldp.net/projects/wdic/
COMMENT=		English dictionary for Korean

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wdic ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
