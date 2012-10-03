# $NetBSD: Makefile,v 1.8 2012/10/03 13:01:46 asau Exp $
#

DISTNAME=	yaesu-0.13
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	Control interface for Yaesu FT-890 HF transceiver

WRKSRC=		${WRKDIR}/yaesu
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin share/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaesu ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/yaesu.README

.include "../../mk/bsd.pkg.mk"
