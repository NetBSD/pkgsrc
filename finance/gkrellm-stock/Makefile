# $NetBSD: Makefile,v 1.38.2.1 2012/10/03 12:07:40 spz Exp $
#

DISTNAME=		gkrellstock-0.5.1
PKGNAME=		gkrellm-stock-0.5.1
PKGREVISION=		21
CATEGORIES=		finance
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gkrellstock/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gkrellstock.sourceforge.net/
COMMENT=		GKrellM2 stock ticker plugin

DEPENDS+=		p5-Finance-Quote>=1.08:../../finance/p5-Finance-Quote

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl:run pkg-config
WRKSRC=			${WRKDIR}/gkrellStock-0.5.1
BUILD_TARGET=		gkrellstock.so
REPLACE_PERL=		${WRKSRC}/GetQuote2
INSTALLATION_DIRS=	bin lib/gkrellm2/plugins

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/GetQuote2 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gkrellstock.so \
		${DESTDIR}${PREFIX}/lib/gkrellm2/plugins

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
