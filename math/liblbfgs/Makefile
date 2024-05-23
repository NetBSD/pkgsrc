# $NetBSD: Makefile,v 1.3 2024/05/23 22:08:49 cheusov Exp $

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

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
