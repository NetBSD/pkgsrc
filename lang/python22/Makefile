# $NetBSD: Makefile,v 1.9 2002/11/23 00:52:49 schmonz Exp $
#

DISTNAME=	Python-2.2.2
PKGNAME=	python22-2.2.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LOWER_OPSYS=	sunos
.endif

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	PY_PLATNAME=${LOWER_OPSYS}
.else
PLIST_SUBST+=	PY_PLATNAME=${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SRC=	${PKGDIR}/PLIST.common ${PKGDIR}/PLIST.${LOWER_OPSYS} \
		${PKGDIR}/PLIST.common_end

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--without-threads
.endif

INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc2.2

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# This comes after bsd.pkg.mk so that the LDFLAGS here overrides the one
# set earlier in the environment (last definition wins).
#
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=      LDFLAGS="${LDFLAGS:S/-Wl,//}"
.endif
