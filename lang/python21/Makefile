# $NetBSD: Makefile,v 1.17 2005/01/23 20:41:46 recht Exp $
#

DISTNAME=	Python-2.1.3
PKGNAME=	python21-2.1.3
PKGREVISION=	5
CATEGORIES=	lang python
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.1.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

USE_LANGUAGES=	c c++
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2.1

INSTALL_TARGET=		altinstall

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	${.CURDIR}/../../lang/python21/PLIST.common
.if exists(${.CURDIR}/../../lang/python21/PLIST.${OPSYS})
PLIST_SRC+=	${.CURDIR}/../../lang/python21/PLIST.${OPSYS}
.endif
PLIST_SRC+=	${.CURDIR}/../../lang/python21/PLIST.common_end

.if ${OPSYS} == "Darwin"
PY_PLATNAME=	${LOWER_OPSYS}
.elif ${OPSYS} == "IRIX"
PY_PLATNAME=	${LOWER_OPSYS:C/\..*//}
.elif ${OPSYS} == "SunOS"
PY_PLATNAME=	sunos${OS_VERSION:C/\..*//}
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME}

# bsddb.so is not built on Solaris (or IRIX?)
BSDDB=
.if ${OPSYS} == "SunOS" || ${OPSYS} == "IRIX"
BSDDB=		"@comment "
.endif
PLIST_SUBST+=	BSDDB=${BSDDB}

PLIST_SUBST+=	PY_VER_SUFFIX=${PY_VER_SUFFIX}

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc${PY_VER_SUFFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This comes after bsd.pkg.mk so that the LDFLAGS here overrides the one
# set earlier in the environment (last definition wins).
#
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=	LDFLAGS="${LDFLAGS:S/-Wl,//}"
.endif
