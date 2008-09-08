# $NetBSD: Makefile,v 1.7 2008/09/08 10:16:06 shannonjr Exp $
#

DISTNAME=	avenger-0.7.9
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mailavenger.org/dist/
COMMENT=	SMTP server with filtering capabilities

PKG_DESTDIR_SUPPORT=	user-destdir

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
