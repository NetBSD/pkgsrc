# $NetBSD: Makefile,v 1.1.1.1 2006/10/25 14:05:31 rillig Exp $
#

DISTNAME=	avenger-0.7.7
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.mailavenger.org/dist/
COMMENT=	SMTP server with filtering capabilities

PKG_SYSCONFSUBDIR=	avenger
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-db=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

.include "options.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
