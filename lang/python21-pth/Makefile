# $NetBSD: Makefile,v 1.1.1.1 2002/08/20 19:58:58 drochner Exp $
#

DISTNAME=	Python-2.1.3
PKGNAME=	python21-pth-2.1.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.1.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-pth

INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc2p1

.include "../../devel/zlib/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# This comes after bsd.pkg.mk so that the LDFLAGS here overrides the one
# set earlier in the environment (last definition wins).
#
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=	LDFLAGS="${LDFLAGS:S/-Wl,//}"
.endif
