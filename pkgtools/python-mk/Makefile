# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 13:41:32 drochner Exp $
#

DISTNAME=	python-mk-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
COMMENT=	common functions for python "distutils" packages

# not strictly needed
DEPENDS+=	python>=1.6:../../lang/python

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_CONFIGURE=	# defined
NO_PATCH=	# defined
NO_BUILD=	# defined

PYMKFILE=	${FILESDIR}/bsd.python.mk

do-install:
	${INSTALL_SCRIPT} ${PYMKFILE} ${PREFIX}/share/mk

.include "../../mk/bsd.pkg.mk"
