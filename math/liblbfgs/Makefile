# $NetBSD: Makefile,v 1.2 2014/11/02 23:09:31 cheusov Exp $

DISTNAME=	liblbfgs-1.10
CATEGORIES=	math
MASTER_SITES=	https://github.com/downloads/chokkan/liblbfgs/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.chokkan.org/software/liblbfgs/
COMMENT=	Library of Limited-memory Broyden-Fletcher-Goldfarb-Shanno (L-BFGS)
LICENSE=	mit

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

AUTOCONF_REQD=	2.50
USE_TOOLS+=	autoconf
pre-configure:
	set -e; cd ${WRKSRC}; autoconf

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
