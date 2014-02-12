# $NetBSD: Makefile,v 1.14 2014/02/12 23:17:35 tron Exp $

DISTNAME=	climm-0.7.1
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	http://www.climm.org/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.climm.org/
COMMENT=	Text-mode ICQ client

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--disable-otr
CONFIGURE_ARGS+=	--disable-tcl
CONFIGURE_ARGS+=	--disable-xmpp
CONFIGURE_ARGS+=	--enable-ssl=openssl

.include "../../chat/libotr/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
