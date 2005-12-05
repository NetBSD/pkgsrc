# $NetBSD: Makefile,v 1.30 2005/12/05 20:50:27 rillig Exp $
#

DISTNAME=	Python-2.2.3
PKGNAME=	python22-2.2.3
PKGREVISION=	7
CATEGORIES=	lang python
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.2.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

CONFLICTS+=	python-[0-9]*

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

PTHREAD_OPTS+=   require
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
PLIST_SUBST+=	PY_PLATNAME=${LOWER_OPSYS:Q}
.elif ${OPSYS} == "IRIX"
PLIST_SUBST+=   PY_PLATNAME=${LOWER_OPSYS:C/\..*//}
.elif ${OPSYS} == "SunOS"
PLIST_SUBST+=	PY_PLATNAME=sunos${OS_VERSION:C/\..*//}
.else
PLIST_SUBST+=	PY_PLATNAME=${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif

PLIST_SUBST+=	PY_VER_SUFFIX=${PY_VER_SUFFIX:Q}

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
