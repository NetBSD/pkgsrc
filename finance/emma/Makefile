# $NetBSD: Makefile,v 1.19 2003/05/02 11:54:50 wiz Exp $
#

DISTNAME=       emma-0.8.2
PKGREVISION=	1
CATEGORIES=	finance
MASTER_SITES=   ${HOMEPAGE}emma/packages/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://rainbow.mimuw.edu.pl/~la181249/
COMMENT=	Money management program

BUILD_USES_MSGFMT=	yes

USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		yes

CONFIGURE_ENV+=		PYTHONBIN=${PYTHONBIN}
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PYTHON_VERSIONS_ACCEPTED=	15

post-extract:
	${RM} ${WRKSRC}/config.cache

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
