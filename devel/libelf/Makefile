# $NetBSD: Makefile,v 1.17 2014/06/05 02:41:09 obache Exp $
#

DISTNAME=		libelf-0.8.13
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.mr511.de/software/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mr511.de/software/english.html
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
