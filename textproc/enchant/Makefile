# $NetBSD: Makefile,v 1.4 2004/02/14 18:26:29 jmmv Exp $
#

DISTNAME=		enchant-1.1.3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=abiword/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.abisource.com/enchant/
COMMENT=		Generic spell checking library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	enchant.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/glib2/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
