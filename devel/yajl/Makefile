# $NetBSD: Makefile,v 1.1.1.1 2012/03/18 16:56:32 abs Exp $

DISTNAME=	2.0.1
PKGNAME=	yajl-${DISTNAME}
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

MAKE_ENV+=	MKDIR="${MKDIR}"
MAKE_ENV+=	CP="${CP}"

BUILD_DIRS=	src

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/src/

.include "../../mk/bsd.pkg.mk"
