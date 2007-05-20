# $NetBSD: Makefile,v 1.1.1.1 2007/05/20 02:42:27 heinz Exp $
#

DISTNAME=		uuid-1.6.0
PKGNAME=		ossp-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.ossp.org/pkg/lib/uuid/

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://www.ossp.org/pkg/lib/uuid/
COMMENT=		C-API and command line tool for generating UUIDs

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		e2fsprogs>1.32 libuuid-[0-9]*

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/uuid.pc.in
GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-dce
CONFIGURE_ARGS+=	--with-cxx
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--without-perl-compat
CONFIGURE_ARGS+=	--without-php
CONFIGURE_ARGS+=	--without-pgsql

.include "../../mk/bsd.pkg.mk"
