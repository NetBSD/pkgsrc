# $NetBSD: Makefile,v 1.6 2006/11/16 22:04:21 reed Exp $
#

DISTNAME=		libelf-0.8.5
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.mr511.de/software/	\
			${MASTER_SITE_SUNSITE:=libs/}
MAINTAINER=		petrov@NetBSD.org
HOMEPAGE=		http://www.mr511.de/software/
COMMENT=		ELF object file access library

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-compat
CONFIGURE_ARGS+=	--disable-nls

.include "../../mk/bsd.pkg.mk"
