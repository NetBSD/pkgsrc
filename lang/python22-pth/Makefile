# $NetBSD: Makefile,v 1.3 2003/05/02 11:55:36 wiz Exp $
#

DISTNAME=	Python-2.2.2
PKGREVISION=	1
PKGNAME=	python22-pth-2.2.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

PLIST_SUBST+=	PY_PLATNAME=${LOWER_OPSYS}${OS_VERSION:C/\..*//}

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-pth
.endif

INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc2p2

.include "../../devel/pth/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# This comes after bsd.pkg.mk so that the LDFLAGS here overrides the one
# set earlier in the environment (last definition wins).
#
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=      LDFLAGS="${LDFLAGS:S/-Wl,//}"
.endif
