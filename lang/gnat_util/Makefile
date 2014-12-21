# $NetBSD: Makefile,v 1.2 2014/12/21 02:39:24 obache Exp $

PKGNAME=	gnat_util-${SNAPSHOT}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
DISTFILES=	gcc-${GCC_VERSION}.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.dragonlace.net/
COMMENT=	Library used to build GNAT source-based tools
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

.include "../../mk/bsd.prefs.mk"
.include "../../lang/gcc-aux/Makefile.version"
.include "Makefile.sources"

MAKE_ENV=	MAKEOBJDIR=${WRKSRC}/obj
USE_LANGUAGES=	c ada

# Automatic package list generation
GENERATE_PLIST=  cd ${DESTDIR}${PREFIX};
GENERATE_PLIST+= ${FIND} * \( -type f -or -type l \) | ${SORT} -dr;

post-extract:
	${MKDIR} ${WRKSRC}/obj
.for f in Makefile gnat_util.gpr sdefault_adb.gnat_util
	${CP} ${FILESDIR}/${f} ${WRKSRC}/
.endfor
.for f in ${GNAT_SRCS}
	${CP} ${WRKDIR}/gcc-${GCC_VERSION}/gcc/ada/${f} ${WRKSRC}/
.endfor

.include "../../mk/bsd.pkg.mk"
