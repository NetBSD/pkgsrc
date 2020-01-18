# $NetBSD: Makefile,v 1.6 2020/01/18 23:33:09 rillig Exp $
#

DISTNAME=		wdic_wob_v3.0
PKGNAME=		wdic-3.0
CATEGORIES=		misc
MASTER_SITES=		http://kldp.net/frs/download.php/1732/

MAINTAINER=		fox9@netb.co.kr
HOMEPAGE=		https://kldp.net/projects/wdic/
COMMENT=		English dictionary for Korean

WRKSRC=			${WRKDIR}

LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wdic ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
