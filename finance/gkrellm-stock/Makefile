# $NetBSD: Makefile,v 1.10 2004/02/24 23:05:57 cube Exp $
#

DISTNAME=		gkrellstock-0.5.1
PKGNAME=		gkrellm-stock-0.5.1
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gkrellstock/}

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://gkrellstock.sourceforge.net/
COMMENT=		GKrellM2 stock ticker plugin

DEPENDS+=		p5-finance-quote>=1.08:../../finance/p5-finance-quote

WRKSRC=			${WRKDIR}/gkrellStock-0.5.1
USE_BUILDLINK3=		yes
ALL_TARGET=		gkrellstock.so
REPLACE_PERL=		${WRKSRC}/GetQuote2

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellstock.so ${PREFIX}/lib/gkrellm2/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/GetQuote2 ${PREFIX}/bin

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
