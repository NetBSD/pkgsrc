# $NetBSD: Makefile,v 1.11 2006/04/17 13:46:39 wiz Exp $
#

DISTNAME=		galculator-1.2.5.2
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=galculator/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://galculator.sourceforge.net/
COMMENT=		Desktop calculator with scientific / RPN modes

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
