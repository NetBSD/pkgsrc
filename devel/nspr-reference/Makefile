# $NetBSD: Makefile,v 1.1.1.1 2005/01/24 19:57:53 jschauma Exp $
#

DISTNAME=		nspr-reference
PKGNAME=		${DISTNAME}-0.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_MOZILLA:=../../nspr/doc/}

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		ftp://ftp.mozilla.org/pub/mozilla.org/nspr/doc/
COMMENT=		HTML Documentation for NSPR

NO_CONNFIGURE=		YES
NO_BUILD=		YES

WRKSRC=			${WRKDIR}/nspr/reference/html

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/nspr
	cd ${WRKSRC} && ${PAX}  -s,.*/CVS.*,, -rwvpe . ${PREFIX}/share/doc/html/nspr/

.include "../../mk/bsd.pkg.mk"
