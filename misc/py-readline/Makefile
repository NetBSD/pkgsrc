# $NetBSD: Makefile,v 1.18 2001/12/20 19:32:27 tron Exp $
#

DISTNAME=	${PY_DISTNAME}
PKGNAME=	py-readline-${PY_VERSION}
WRKSRC=		${PY_WRKSRC}
CATEGORIES=	misc
MASTER_SITES=	${PY_MASTER_SITES}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/tut/interacting.html
COMMENT=	line editing support for Python

EXTRACT_ELEMENTS=	${PY_MODULES}/readline.c

USE_GNU_READLINE=	# defined

.include "../../devel/readline/buildlink.mk"

PY_SETUP_SUBST+=	BUILDLINK_CPPFLAGS=${_BUILDLINK_CPPFLAGS}
PY_SETUP_SUBST+=	BUILDLINK_LDFLAGS=${_BUILDLINK_LDFLAGS}

do-configure:	python-std-do-configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/readline.so ${PY_LIBDIR}/lib-dynload

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
