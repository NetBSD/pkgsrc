# $NetBSD: Makefile,v 1.22 2026/01/04 15:40:49 wiz Exp $

DISTNAME=	libjit-0.1.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://download.savannah.gnu.org/releases/dotgnu-pnet/libjit-releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/libjit/
COMMENT=	Just-In-Time compilation functionality

LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex yacc makeinfo
GNU_CONFIGURE=	yes
INFO_FILES=	yes

CONFIGURE_ARGS.NetBSD+=	ac_cv_header_tgmath_h=no

# this is supposed to be generated, not shipped
post-extract:
	rm -f ${WRKSRC}/include/jit/jit-arch.h

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
