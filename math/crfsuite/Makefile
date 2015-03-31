# $NetBSD: Makefile,v 1.3 2015/03/31 15:49:15 joerg Exp $

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

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CONFIGURE_ARGS+=	--disable-sse2
.endif

pre-configure:
	set -e; cd ${WRKSRC}; autoreconf -sif

post-install:
	set -e; cd ${WRKSRC}; \
	${INSTALL_SCRIPT} example/*.py ${DESTDIR}${PREFIX}/share/examples/crfsuite

.include "../../lang/python/application.mk"
.include "../../math/liblbfgs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
