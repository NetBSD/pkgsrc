# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 21:11:35 wiz Exp $
#

DISTNAME=		enchant-0.4.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=abiword/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://abiword.sourceforge.net/enchant/
COMMENT=		Generic spell checking library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/enchant.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/glib2/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
