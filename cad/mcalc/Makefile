# $NetBSD: Makefile,v 1.2 2002/08/23 01:31:24 dmcmahill Exp $
#

DISTNAME=	mcalc-1.5
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcalc/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://mcalc.sourceforge.net
COMMENT=	JavaScript based microstrip analysis/synthesis calculator

NO_BUILD=	yes

MCALCBASE?=	share/${PKGNAME}

PLIST_SUBST+=	MCALCBASE=${MCALCBASE}
MESSAGE_SUBST+=	MCALCBASE=${MCALCBASE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${MCALCBASE}
	${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/${MCALCBASE}/

.include "../../mk/bsd.pkg.mk"
