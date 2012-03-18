# $NetBSD: Makefile,v 1.2 2012/03/18 23:22:03 abs Exp $

DISTNAME=	2.0.1
PKGNAME=	yajl-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/lloyd/yajl/tarball/
DIST_SUBDIR=	yajl
EXTRACT_SUFX=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lloyd.github.com/yajl/
COMMENT=	Small JSON library written in ANSI C
LICENSE=	modified-bsd

EXTRACT_CMD=	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}
# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

WRKSRC=		${WRKDIR}/lloyd-yajl-f4b2b1a

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	tar
USE_CMAKE=	yes

.include "../../mk/bsd.pkg.mk"
