# $NetBSD: Makefile,v 1.5 2014/01/05 03:23:21 rodent Exp $

DISTNAME=	2.0.1
PKGNAME=	yajl-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	http://nodeload.github.com/lloyd/yajl/tarball/
DIST_SUBDIR=	yajl
EXTRACT_SUFX=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lloyd.github.com/yajl/
COMMENT=	Small JSON library written in ANSI C
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/lloyd-yajl-f4b2b1a

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	tar gzcat
USE_CMAKE=	yes

EXTRACT_OPTS=	-c gzip -f tar

.include "../../mk/bsd.pkg.mk"
