# $NetBSD: Makefile,v 1.3 2004/08/13 07:09:01 cube Exp $
#

DISTNAME=		libelf-0.8.5
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.stud.uni-hannover.de/~michael/software/

MAINTAINER=		petrov@NetBSD.org
HOMEPAGE=		http://www.stud.uni-hannover.de/~michael/software/
COMMENT=		ELF object file access library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--disable-compat
CONFIGURE_ARGS+=	--disable-nls

.include "../../mk/bsd.pkg.mk"
