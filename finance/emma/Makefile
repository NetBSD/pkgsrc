# $NetBSD: Makefile,v 1.9 2001/09/27 23:18:03 jlam Exp $
#

DISTNAME=       emma-0.8-1
PKGNAME=	emma-0.8.1
WRKSRC=         ${WRKDIR}/emma-0.7
CATEGORIES=	finance
MASTER_SITES=   ${HOMEPAGE}emma/packages/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://rainbow.mimuw.edu.pl/~la181249/
COMMENT=	Money management program

BUILD_DEPENDS+=	automake>=1.4:../../devel/automake
DEPENDS+=	gnome-libs-[0-9]*:../../x11/gnome-libs
DEPENDS+=	python>=2.0:../../lang/python
DEPENDS+=	py-mxDateTime-[0-9]*:../../time/py-mxDateTime

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	yes
BUILD_USES_MSGFMT=	yes

WRKSRC=		${WRKDIR}/emma-0.8

post-extract:
	for FILE in install-sh missing mkinstalldirs; do \
	  ${RM} -f ${WRKSRC}/$$FILE; \
	  ${CP} ${LOCALBASE}/share/automake/$$FILE ${WRKSRC}/$$FILE; \
	done

.include "../../mk/bsd.pkg.mk"
