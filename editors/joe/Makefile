# $NetBSD: Makefile,v 1.21 2004/10/08 23:50:37 kristerw Exp $

DISTNAME=	joe-3.1
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=joe-editor/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://joe-editor.sourceforge.net/
COMMENT=	Joe's own editor

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS=		--sysconfdir="${PREFIX}/share/examples"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
