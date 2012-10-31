# $NetBSD: Makefile,v 1.7 2012/10/31 11:19:37 asau Exp $

DISTNAME=	ragel-6.7
CATEGORIES=	devel
MASTER_SITES=	http://www.complang.org/ragel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.complang.org/ragel/
COMMENT=	State machine compiler
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/ragel-guide.pdf \
		${DESTDIR}${PREFIX}/share/doc/ragel

.include "../../mk/bsd.pkg.mk"
