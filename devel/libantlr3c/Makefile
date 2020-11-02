# $NetBSD: Makefile,v 1.1 2020/11/02 12:25:56 nia Exp $

DISTNAME=	libantlr3c-3.4
CATEGORIES=	devel
MASTER_SITES=	https://www.antlr3.org/download/C/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.antlr3.org/
COMMENT=	ANother Tool for Language Recognition (C runtime)
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.for platform in ${LP64PLATFORMS}
.  if ${MACHINE_PLATFORM:M${platform}}
CONFIGURE_ARGS+=	--enable-64bit
.  endif
.endfor

CONFIGURE_ARGS+=	--disable-abiflags

.include "../../mk/bsd.pkg.mk"
