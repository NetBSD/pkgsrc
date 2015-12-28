# $NetBSD: Makefile,v 1.1 2015/12/28 15:08:54 tsutsui Exp $

DISTNAME=		wm-icons-0.4.0
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wm-icons/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		http://wm-icons.sourceforge.net/
COMMENT=		Efficient configurable icons distribution
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-all-sets

INSTALLATION_DIRS+=     share/icons/wm-icons

.include "../../mk/bsd.pkg.mk"
