# $NetBSD: Makefile,v 1.2 2023/06/06 12:41:44 riastradh Exp $

DISTNAME=	hamlet-2.0.0
CATEGORIES=	lang
MASTER_SITES=	https://people.mpi-sws.org/~rossberg/hamlet/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://people.mpi-sws.org/~rossberg/hamlet/
COMMENT=	Faithful and complete implementation of the Standard ML
LICENSE=	hamlet-license

TOOL_DEPENDS+=	moscow_ml>=2.10:../../lang/moscow_ml

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

BUILD_TARGET=	with-mosml

INSTALL_MAKE_FLAGS+=	INSTALLDIR=${PREFIX}/hamlet

INSTALLATION_DIRS+=	bin

post-install:
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/hamlet
	${ECHO} '${PREFIX}/hamlet/hamlet "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/hamlet
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/hamlet

.include "../../mk/bsd.pkg.mk"
