# $NetBSD: Makefile,v 1.24 2005/01/25 13:09:03 tv Exp $
#

DISTNAME=	Python-2.2.3
PKGNAME=	python22-2.2.3
PKGREVISION=	3
CATEGORIES=	lang python
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.2.3/
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

PY_VER_SUFFIX=	2.2

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	${.CURDIR}/../../lang/python22/PLIST.common
.if exists(${.CURDIR}/../../lang/python22/PLIST.${OPSYS})
PLIST_SRC+=	${.CURDIR}/../../lang/python22/PLIST.${OPSYS}
.endif
PLIST_SRC+=	${.CURDIR}/../../lang/python22/PLIST.common_end

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
PLIST_SUBST+=	PY_PLATNAME=${LOWER_OPSYS}
.elif ${OPSYS} == "IRIX"
PLIST_SUBST+=   PY_PLATNAME=${LOWER_OPSYS:C/\..*//}
.elif ${OPSYS} == "SunOS"
PLIST_SUBST+=	PY_PLATNAME=sunos${OS_VERSION:C/\..*//}
.else
PLIST_SUBST+=	PY_PLATNAME=${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif

PLIST_SUBST+=	PY_VER_SUFFIX=${PY_VER_SUFFIX}

INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc${PY_VER_SUFFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This comes after bsd.pkg.mk so that the LDFLAGS here overrides the one
# set earlier in the environment (last definition wins).
#
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=      LDFLAGS="${LDFLAGS:S/-Wl,//}"
.endif
