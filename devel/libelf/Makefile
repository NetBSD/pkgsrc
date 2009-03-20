# $NetBSD: Makefile,v 1.10 2009/03/20 20:01:42 joerg Exp $
#

DISTNAME=		libelf-0.8.10
CATEGORIES=		devel
MASTER_SITES=		http://www.mr511.de/software/english.html

MAINTAINER=		petrov@NetBSD.org
HOMEPAGE=		http://www.mr511.de/software/
COMMENT=		ELF object file access library

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	instroot=${DESTDIR}

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-compat
CONFIGURE_ARGS+=	--disable-nls

.include "../../mk/bsd.pkg.mk"
