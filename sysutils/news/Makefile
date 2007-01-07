# $NetBSD: Makefile,v 1.6 2007/01/07 09:14:12 rillig Exp $
#

DISTNAME=		news-0.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.netmeister.org/apps/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.netmeister.org/
COMMENT=		System V news(1)

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/news ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/news.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
.  include "../../pkgtools/libnbcompat/buildlink3.mk" # for utimes()
.endif

.include "../../mk/bsd.pkg.mk"
