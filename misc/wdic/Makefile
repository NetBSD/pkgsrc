# $NetBSD: Makefile,v 1.2 2008/03/04 19:21:12 jlam Exp $
#

DISTNAME=		wdic_wob_v3.0
PKGNAME=		wdic-3.0
CATEGORIES=		misc
MASTER_SITES=		http://kldp.net/frs/download.php/1732/

MAINTAINER=		fox9@netb.co.kr
HOMEPAGE=		http://kldp.net/projects/wdic/
COMMENT=		English dictionary for Korean

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wdic ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
