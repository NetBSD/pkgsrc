# $NetBSD: Makefile,v 1.16 2001/06/10 00:08:46 jlam Exp $
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

PY_SETUP_SUBST+=	BUILDLINK_INCDIR=${BUILDLINK_INCDIR}
PY_SETUP_SUBST+=	BUILDLINK_LIBDIR=${BUILDLINK_LIBDIR}

do-configure:	python-std-do-configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/readline.so ${PY_LIBDIR}/lib-dynload

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
