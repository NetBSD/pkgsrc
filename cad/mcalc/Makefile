# $NetBSD: Makefile,v 1.5 2004/02/17 02:52:35 dmcmahill Exp $
#

DISTNAME=	mcalc-1.5
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcalc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://mcalc.sourceforge.net/
COMMENT=	JavaScript based microstrip analysis/synthesis calculator

PKG_INSTALLATION_TYPES= overwrite pkgviews

NO_BUILD=	yes

MCALCBASE?=	share/${PKGNAME}

PLIST_SUBST+=	MCALCBASE=${MCALCBASE}
MESSAGE_SUBST+=	MCALCBASE=${MCALCBASE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${MCALCBASE}
	${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/${MCALCBASE}/

.include "../../mk/bsd.pkg.mk"
