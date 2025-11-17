# $NetBSD: Makefile,v 1.14 2025/11/17 11:00:26 wiz Exp $
#

DISTNAME=	mcalc-1.6
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcalc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mcalc.sourceforge.net/
COMMENT=	JavaScript based microstrip analysis/synthesis calculator

NO_BUILD=	yes

MCALCBASE?=	share/${PKGNAME}

PLIST_SUBST+=	MCALCBASE=${MCALCBASE:Q}
MESSAGE_SUBST+=	MCALCBASE=${MCALCBASE}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${MCALCBASE}
	${INSTALL_DATA} ${WRKSRC}/* ${DESTDIR}${PREFIX}/${MCALCBASE}/

.include "../../mk/bsd.pkg.mk"
