# $NetBSD: Makefile,v 1.16 2002/10/09 18:19:15 wiz Exp $
#

DISTNAME=       emma-0.8-1
PKGNAME=	emma-0.8.1
PKGREVISION=	1
WRKSRC=         ${WRKDIR}/emma-0.7
CATEGORIES=	finance
MASTER_SITES=   ${HOMEPAGE}emma/packages/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-am${EXTRACT_SUFX}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://rainbow.mimuw.edu.pl/~la181249/
COMMENT=	Money management program

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
BUILD_USES_MSGFMT=	yes
CONFIGURE_ENV+=	PYTHONBIN=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	15

WRKSRC=		${WRKDIR}/emma-0.8

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
