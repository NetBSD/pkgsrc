# $NetBSD: Makefile,v 1.6 2001/06/30 16:56:30 tron Exp $
#

DISTNAME=       emma-0.8-1
PKGNAME=	emma-0.8.1
WRKSRC=         ${WRKDIR}/emma-0.7
CATEGORIES=	finance
MASTER_SITES=   ${HOMEPAGE}emma/packages/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://rainbow.mimuw.edu.pl/~la181249/
COMMENT=	Money management program

BUILD_DEPENDS+=	automake-1.4:../../devel/automake
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	python>=2.0:../../lang/python

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

WRKSRC=		${WRKDIR}/emma-0.8

post-extract:
	for FILE in install-sh missing mkinstalldirs; do \
	  ${RM} -f ${WRKSRC}/$$FILE; \
	  ${CP} ${LOCALBASE}/share/automake/$$FILE ${WRKSRC}/$$FILE; \
	done

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
