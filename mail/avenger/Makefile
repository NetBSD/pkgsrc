# $NetBSD: Makefile,v 1.22 2019/08/11 13:21:24 wiz Exp $

DISTNAME=	avenger-0.8.4
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://www.mailavenger.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mailavenger.org/
COMMENT=	SMTP server with filtering capabilities
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

CONFLICTS=		deliver-[0-9]*

BDB_ACCEPTED=		db4 db5
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-db=${BDBBASE}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		BDB_TYPE="${BDB_TYPE}"
PKG_SYSCONFSUBDIR=	avenger

LDFLAGS.SunOS+=		-lsocket -lnsl
CFLAGS.SunOS+=		-DDBM_RDONLY=O_RDONLY

.include "options.mk"

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
