# $NetBSD: Makefile,v 1.10 2014/10/09 14:06:01 wiz Exp $
#

DISTNAME=	mcalc-1.6
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcalc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://mcalc.sourceforge.net/
COMMENT=	JavaScript based microstrip analysis/synthesis calculator

NO_BUILD=	yes

MCALCBASE?=	share/${PKGNAME}

PLIST_SUBST+=	MCALCBASE=${MCALCBASE:Q}
MESSAGE_SUBST+=	MCALCBASE=${MCALCBASE}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${MCALCBASE}
	${INSTALL_DATA} ${WRKSRC}/* ${DESTDIR}${PREFIX}/${MCALCBASE}/

.include "../../mk/bsd.pkg.mk"
