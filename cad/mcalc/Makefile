# $NetBSD: Makefile,v 1.1.1.1 2001/11/15 03:10:45 dmcmahill Exp $
#

DISTNAME=	mcalc-1.4
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
