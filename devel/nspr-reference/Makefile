# $NetBSD: Makefile,v 1.4 2007/12/22 07:22:08 obache Exp $
#

DISTNAME=		nspr-reference
PKGNAME=		${DISTNAME}-0.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_MOZILLA_ALL:=nspr/doc/}

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		ftp://ftp.mozilla.org/pub/mozilla.org/nspr/doc/
COMMENT=		HTML Documentation for NSPR

NO_CONFIGURE=		YES
NO_BUILD=		YES

WRKSRC=			${WRKDIR}/nspr/reference/html

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nspr/html
	cd ${WRKSRC} && ${PAX}  -s,.*/CVS.*,, -rwvpe . ${PREFIX}/share/doc/nspr/html

.include "../../mk/bsd.pkg.mk"
