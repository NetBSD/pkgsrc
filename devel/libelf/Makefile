# $NetBSD: Makefile,v 1.19 2026/11/10 10:02:56 yurix Exp $

DISTNAME=		libelf-0.8.13
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		https://fossies.org/linux/misc/old/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://web.archive.org/web/20170211200259/http://www.mr511.de/software/english.html
COMMENT=		ELF object file access library
LICENSE=		gnu-lgpl-v2

INSTALL_MAKE_FLAGS+=	instroot=${DESTDIR}

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf

PKGCONFIG_OVERRIDE+=	libelf.pc.in

pre-configure:
	(cd ${WRKSRC} && autoconf)

CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-compat
CONFIGURE_ARGS+=	--disable-nls

.include "../../mk/bsd.pkg.mk"
