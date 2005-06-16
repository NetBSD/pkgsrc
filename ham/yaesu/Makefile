# $NetBSD: Makefile,v 1.5 2005/06/16 06:57:59 jlam Exp $
#

DISTNAME=	yaesu-0.12
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	Control interface for Yaesu FT-890 HF transceiver

WRKSRC=		${WRKDIR}/yaesu
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin share/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaesu ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/yaesu.README

.include "../../mk/bsd.pkg.mk"
