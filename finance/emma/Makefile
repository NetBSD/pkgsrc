# $NetBSD: Makefile,v 1.14 2002/09/21 23:46:50 jlam Exp $
#

DISTNAME=       emma-0.8-1
PKGNAME=	emma-0.8.1
PKGREVISION=	1
WRKSRC=         ${WRKDIR}/emma-0.7
CATEGORIES=	finance
MASTER_SITES=   ${HOMEPAGE}emma/packages/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://rainbow.mimuw.edu.pl/~la181249/
COMMENT=	Money management program

BUILD_DEPENDS+=	automake>=1.4:../../devel/automake
DEPENDS+=	gnome-libs>=1.4.1.2nb1:../../x11/gnome-libs

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	yes
BUILD_USES_MSGFMT=	yes
CONFIGURE_ENV+=	PYTHONBIN=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED=	15

WRKSRC=		${WRKDIR}/emma-0.8

post-extract:
	for FILE in install-sh missing mkinstalldirs; do \
	  ${RM} -f ${WRKSRC}/$$FILE; \
	  ${CP} ${LOCALBASE}/share/automake/$$FILE ${WRKSRC}/$$FILE; \
	done

.include "../../lang/python/application.mk"
.include "../../time/py-mxDateTime/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
