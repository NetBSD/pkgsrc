# $NetBSD: Makefile,v 1.1.1.1 2009/12/11 19:53:57 drochner Exp $
#

DISTNAME=	muparser_v130
PKGNAME=	muparser-130
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=muparser/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://muparser.sourceforge.net/
COMMENT=	Parser for mathematical expressions

WRKSRC=		${WRKDIR}/muparser
GNU_CONFIGURE=	yes
#USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	build/autoconf/muparser.pc.in

do-test:
	cd ${WRKSRC}/samples/example1 && echo quit | ./example1

.include "../../mk/bsd.pkg.mk"
