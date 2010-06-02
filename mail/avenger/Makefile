# $NetBSD: Makefile,v 1.8 2010/06/02 12:39:44 adam Exp $

DISTNAME=	avenger-0.8.1
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mailavenger.org/
COMMENT=	SMTP server with filtering capabilities

PKG_DESTDIR_SUPPORT=	user-destdir

BDB_ACCEPTED=		db4 db5
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-db=${BDBBASE}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		BDB_TYPE="${BDB_TYPE}"
PKG_SYSCONFSUBDIR=	avenger

.include "options.mk"

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
