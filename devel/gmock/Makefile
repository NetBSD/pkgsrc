# $NetBSD: Makefile,v 1.2 2012/10/31 11:17:01 asau Exp $
#

DISTNAME=	gmock-1.6.0
CATEGORIES=	devel
MASTER_SITES=	http://googlemock.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/googlemock/
COMMENT=	C++ Mocking Framework
LICENSE=	modified-bsd

INSTALLATION_DIRS=	bin

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_LIBTOOL=	yes

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing dynamic python
SUBST_FILES.fix-python+=	gtest/scripts/*py
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

CONFIGURE_ARGS+=	--enable-external-gtest

pre-configure:
	${RM} -r ${WRKSRC}/gtest
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gmock-config ${DESTDIR}${PREFIX}/bin

.include "../../devel/googletest/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
