# $NetBSD: Makefile,v 1.2 2002/04/09 04:33:18 jlam Exp $
#

DISTNAME=	Python-2.2
PKGNAME=	python22-2.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-threads

INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc2.2

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# This comes after bsd.pkg.mk so that the LDFLAGS here overrides the one
# set earlier in the environment (last definition wins).
#
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=      LDFLAGS="${LDFLAGS:S/-Wl,//}"
.endif
