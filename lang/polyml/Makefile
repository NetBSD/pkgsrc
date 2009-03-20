# $NetBSD: Makefile,v 1.1.1.1 2009/03/20 21:12:51 asau Exp $

DISTNAME=	polyml.5.2.1
PKGNAME=	polyml-5.2.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=polyml/}

MAINTAINER=	asau@NetBSD.org
HOMEPAGE=	http://polyml.org/
COMMENT=	Poly/ML is an implementation of Standard ML

# ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-sparc *-*-powerpc
# Dumps core on NetBSD/amd64

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

# Fix URL in documentation:
SUBST_CLASSES+=		url
SUBST_STAGE.url=	post-patch
SUBST_MESSAGE.url=	Fixing URL in manual pages
SUBST_FILES.url=	poly.1 polyimport.1
SUBST_SED.url=		-e 's|http://www\.poly\.org|http://www.polyml.org|'

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
