# $NetBSD: Makefile,v 1.10 2005/01/06 16:50:39 wiz Exp $
#

DISTNAME=		enchant-1.1.5
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=abiword/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.abisource.com/enchant/
COMMENT=		Generic spell checking library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
