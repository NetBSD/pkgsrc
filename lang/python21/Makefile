# $NetBSD: Makefile,v 1.10 2003/06/06 18:14:11 drochner Exp $
#

DISTNAME=	Python-2.1.3
PKGNAME=	python21-2.1.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.1.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-threads
MAKE_ENV+=	LINK_ALL_LIBGCC_HACK=${LINK_ALL_LIBGCC_HACK:Q}

INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc2.1

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# This comes after bsd.pkg.mk so that the LDFLAGS here overrides the one
# set earlier in the environment (last definition wins).
#
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=	LDFLAGS="${LDFLAGS:S/-Wl,//}"
.endif
