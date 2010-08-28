# $NetBSD: Makefile,v 1.15 2010/08/28 09:16:35 cherry Exp $
#

DISTNAME=		libelf-0.8.13
CATEGORIES=		devel
MASTER_SITES=		http://www.mr511.de/software/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mr511.de/software/english.html
COMMENT=		ELF object file access library
LICENSE=		gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
