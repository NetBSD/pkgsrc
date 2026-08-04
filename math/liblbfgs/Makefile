# $NetBSD: Makefile,v 1.4 2026/08/04 20:29:07 wiz Exp $

DISTNAME=	liblbfgs-1.10
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=liblbfgs/}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.chokkan.org/software/liblbfgs/
COMMENT=	Library of Limited-memory Broyden-Fletcher-Goldfarb-Shanno (L-BFGS)
LICENSE=	mit

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

AUTOCONF_REQD+=	2.50
USE_TOOLS+=	autoconf
pre-configure:
	set -e; cd ${WRKSRC}; autoconf

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
