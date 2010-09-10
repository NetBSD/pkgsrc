# $NetBSD: Makefile,v 1.8 2010/09/10 08:28:13 wiz Exp $

DISTNAME=	climm-0.6.3
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.climm.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.climm.org/
COMMENT=	Text-mode ICQ client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--disable-tcl --disable-otr --enable-ssl=openssl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
