# $NetBSD: Makefile,v 1.2 2003/03/29 12:41:22 jmmv Exp $
#

DISTNAME=	yaesu-0.12
WRKSRC=		${WRKDIR}/yaesu
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	control interface for Yaesu FT-890 HF transceiver

NO_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaesu ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/yaesu.README

.include "../../mk/bsd.pkg.mk"
