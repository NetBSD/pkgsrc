# $NetBSD: Makefile,v 1.8 2009/03/17 21:40:45 darcy Exp $
#

DISTNAME=		nspr-reference
PKGNAME=		${DISTNAME}-0.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_MOZILLA_ALL:=nspr/doc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.mozilla.org/pub/mozilla.org/nspr/doc/
COMMENT=		HTML Documentation for NSPR

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		YES
NO_BUILD=		YES
USE_TOOLS+=	pax

WRKSRC=			${WRKDIR}/nspr/reference/html

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/nspr/html
	cd ${WRKSRC} && pax  -s,.*/CVS.*,, -rwvpe . \
		${DESTDIR}${PREFIX}/share/doc/nspr/html

.include "../../mk/bsd.pkg.mk"
