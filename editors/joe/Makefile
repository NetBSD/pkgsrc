# $NetBSD: Makefile,v 1.27 2005/12/29 06:21:38 jlam Exp $

DISTNAME=	joe-3.3
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
