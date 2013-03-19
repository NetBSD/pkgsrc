# $NetBSD: Makefile,v 1.7 2013/03/19 10:24:24 drochner Exp $
#

DISTNAME=		uuid-1.6.2
PKGNAME=		ossp-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.ossp.org/pkg/lib/uuid/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ossp.org/pkg/lib/uuid/
COMMENT=		C-API and command line tool for generating UUIDs

CONFLICTS=		libuuid-[0-9]* # libuuid.* uuid.pc uuid.3
# conflicts with package in pkgsrc-wip
#CONFLICTS+=		e2fsprogs>1.32 # libuuid.* uuid.pc uuid.3

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
