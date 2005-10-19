# $NetBSD: Makefile,v 1.19 2005/10/19 23:33:37 wiz Exp $
#

DISTNAME=		gkrellstock-0.5.1
PKGNAME=		gkrellm-stock-0.5.1
PKGREVISION=		3
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gkrellstock/}

MAINTAINER=		cube@NetBSD.org
HOMEPAGE=		http://gkrellstock.sourceforge.net/
COMMENT=		GKrellM2 stock ticker plugin

DEPENDS+=		p5-Finance-Quote>=1.08:../../finance/p5-Finance-Quote

USE_TOOLS+=		pkg-config
WRKSRC=			${WRKDIR}/gkrellStock-0.5.1
BUILD_TARGET=		gkrellstock.so
REPLACE_PERL=		${WRKSRC}/GetQuote2
INSTALLATION_DIRS=	bin lib/gkrellm2/plugins

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellstock.so ${PREFIX}/lib/gkrellm2/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/GetQuote2 ${PREFIX}/bin

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
