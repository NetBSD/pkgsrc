# $NetBSD: Makefile,v 1.7 2008/03/04 15:51:59 jlam Exp $
#

DISTNAME=	yaesu-0.13
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/ham/}

MAINTAINER=	dawszy@arhea.net
#HOMEPAGE=	not known
COMMENT=	Control interface for Yaesu FT-890 HF transceiver

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/yaesu
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin share/doc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yaesu ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/yaesu.README

.include "../../mk/bsd.pkg.mk"
