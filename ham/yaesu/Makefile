# $NetBSD: Makefile,v 1.3 2003/07/21 16:52:11 martti Exp $
#

DISTNAME=	yaesu-0.12
WRKSRC=		${WRKDIR}/yaesu
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	Control interface for Yaesu FT-890 HF transceiver

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaesu ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/yaesu.README

.include "../../mk/bsd.pkg.mk"
