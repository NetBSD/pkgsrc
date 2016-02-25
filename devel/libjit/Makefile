# $NetBSD: Makefile,v 1.19 2016/02/25 12:12:48 jperkin Exp $
#

DISTNAME=	libjit-0.1.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/dotgnu-pnet/libjit-releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.southern-storm.com.au/libjit.html
COMMENT=	Just-In-Time compilation functionality

LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake lex yacc makeinfo
GNU_CONFIGURE=		yes
INFO_FILES=	yes

CONFIGURE_ARGS.NetBSD+=	ac_cv_header_tgmath_h=no

# this is supposed to be generated, not shipped
post-extract:
	rm -f ${WRKSRC}/include/jit/jit-arch.h

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
