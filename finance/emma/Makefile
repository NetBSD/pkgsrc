# $NetBSD: Makefile,v 1.26 2004/10/03 00:14:41 tv Exp $

DISTNAME=       emma-0.8.2
PKGREVISION=	4
CATEGORIES=	finance
MASTER_SITES=   ${HOMEPAGE}emma/packages/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rainbow.mimuw.edu.pl/~la181249/
COMMENT=	Money management program

BUILD_USES_MSGFMT=	yes

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

CONFIGURE_ENV+=		PYTHONBIN=${PYTHONBIN}
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PYTHON_VERSIONS_ACCEPTED=	15

post-extract:
	${RM} ${WRKSRC}/config.cache

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../time/py-mxDateTime/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
