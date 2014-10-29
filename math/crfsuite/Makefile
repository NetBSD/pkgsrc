# $NetBSD: Makefile,v 1.1.1.1 2014/10/29 23:13:21 cheusov Exp $

DISTNAME=	0.12
PKGNAME=	crfsuite-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://github.com/chokkan/crfsuite/archive/
DIST_SUBDIR=	crfsuite

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/chokkan/crfsuite
COMMENT=	Fast implementation of Conditional Random Fields (CRFs)
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/crfsuite-0.12
USE_LANGUAGES=	c c++

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

AUTOCONF_REQD=	2.50
USE_TOOLS+=	autoconf autoreconf automake

CONFIGURE_ARGS+=	--with-liblbfgs=${PREFIX}

pre-configure:
	set -e; cd ${WRKSRC}; autoreconf -sif

.include "../../math/liblbfgs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
