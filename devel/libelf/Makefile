# $NetBSD: Makefile,v 1.16 2012/10/31 11:17:12 asau Exp $
#

DISTNAME=		libelf-0.8.13
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

pre-configure:
	(cd ${WRKSRC} && autoconf)

CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-compat
CONFIGURE_ARGS+=	--disable-nls

.include "../../mk/bsd.pkg.mk"
