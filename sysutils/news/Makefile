# $NetBSD: Makefile,v 1.4 2005/11/01 19:07:02 tv Exp $
#

DISTNAME=		news-0.2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.netmeister.org/apps/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.netmeister.org/
COMMENT=		System V news(1)

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/news ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/news.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
