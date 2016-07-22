# $NetBSD: Makefile,v 1.1 2016/07/22 02:45:44 cheusov Exp $

DISTNAME=	classias-1.1.0.20160722
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheusov/}

COMMENT=	Collection of machine-learning algorithms for classification
LICENSE=	modified-bsd

GITHUB_PROJECT=	classias
MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.chokkan.org/software/classias/

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes

USE_TOOLS+=	autoconf autoreconf automake

CONFIGURE_ARGS+=	--with-liblbfgs=${PREFIX}

.include "../../mk/bsd.prefs.mk"

pre-configure:
	set -e; cd ${WRKSRC}; ${SH} ./autogen.sh

.include "../../math/liblbfgs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
