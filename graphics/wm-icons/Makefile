# $NetBSD: Makefile,v 1.3 2020/01/18 23:32:38 rillig Exp $

DISTNAME=		wm-icons-0.4.0
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wm-icons/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://wm-icons.sourceforge.net/
COMMENT=		Efficient configurable icons distribution
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-all-sets

INSTALLATION_DIRS+=	share/icons/wm-icons

.include "../../mk/bsd.pkg.mk"
