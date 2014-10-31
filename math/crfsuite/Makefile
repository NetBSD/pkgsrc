# $NetBSD: Makefile,v 1.2 2014/10/31 00:54:02 cheusov Exp $

DISTNAME=	0.12
PKGNAME=	crfsuite-${DISTNAME}
PKGREVISION=	1
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
AUTO_MKDIRS=	yes

AUTOCONF_REQD=	2.50
USE_TOOLS+=	autoconf autoreconf automake

CONFIGURE_ARGS+=	--with-liblbfgs=${PREFIX}

REPLACE_PYTHON=		example/*.py

pre-configure:
	set -e; cd ${WRKSRC}; autoreconf -sif

post-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_SCRIPT} example/*.py ${DESTDIR}${PREFIX}/share/examples/crfsuite

.include "../../lang/python/application.mk"
.include "../../math/liblbfgs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
