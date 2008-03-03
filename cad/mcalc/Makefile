# $NetBSD: Makefile,v 1.7 2008/03/03 01:50:27 jlam Exp $
#

DISTNAME=	mcalc-1.5
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcalc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://mcalc.sourceforge.net/
COMMENT=	JavaScript based microstrip analysis/synthesis calculator

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

MCALCBASE?=	share/${PKGNAME}

PLIST_SUBST+=	MCALCBASE=${MCALCBASE:Q}
MESSAGE_SUBST+=	MCALCBASE=${MCALCBASE}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${MCALCBASE}
	${INSTALL_DATA} ${WRKSRC}/* ${DESTDIR}${PREFIX}/${MCALCBASE}/

.include "../../mk/bsd.pkg.mk"
