# $NetBSD: Makefile,v 1.13 2019/11/03 10:39:21 rillig Exp $

DISTNAME=	nspr-reference
PKGNAME=	${DISTNAME}-0.1
PKGREVISION=	1
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_MOZILLA_ALL:=nspr/doc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.mozilla.org/en-US/docs/Mozilla/Projects/NSPR
COMMENT=	HTML Documentation for NSPR

NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_TOOLS+=	pax

WRKSRC=			${WRKDIR}/nspr/reference/html

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/nspr/html
	cd ${WRKSRC} && pax  -s,.*/CVS.*,, -rwvpp . \
		${DESTDIR}${PREFIX}/share/doc/nspr/html

.include "../../mk/bsd.pkg.mk"
