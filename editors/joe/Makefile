# $NetBSD: Makefile,v 1.29 2006/07/07 18:22:00 adam Exp $

DISTNAME=	joe-3.4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=joe-editor/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://joe-editor.sourceforge.net/
COMMENT=	Joe's own editor

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX:Q}/share/examples

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
