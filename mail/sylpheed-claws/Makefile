# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 18:52:23 jlam Exp $

DISTNAME=	sylpheed-0.7.6claws
PKGNAME=	sylpheed-claws-0.7.6
CATEGORIES=	mail news x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sylpheed-claws/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://sylpheed-claws.sourceforge.net/
COMMENT=	X based e-mail and netnews client

CONFLICTS=	sylpheed-*

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-ssl

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../graphics/imlib/buildlink.mk"
.include "../../security/gpgme/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
