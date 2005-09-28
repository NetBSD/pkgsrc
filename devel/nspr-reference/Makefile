# $NetBSD: Makefile,v 1.2 2005/09/28 22:38:11 rillig Exp $
#

DISTNAME=		nspr-reference
PKGNAME=		${DISTNAME}-0.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_MOZILLA:=../../nspr/doc/}

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		ftp://ftp.mozilla.org/pub/mozilla.org/nspr/doc/
COMMENT=		HTML Documentation for NSPR

NO_CONFIGURE=		YES
NO_BUILD=		YES

WRKSRC=			${WRKDIR}/nspr/reference/html

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/nspr
	cd ${WRKSRC} && ${PAX}  -s,.*/CVS.*,, -rwvpe . ${PREFIX}/share/doc/html/nspr/

.include "../../mk/bsd.pkg.mk"
