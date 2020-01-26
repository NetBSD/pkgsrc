# $NetBSD: Makefile,v 1.10 2020/01/26 17:31:04 rillig Exp $

DISTNAME=	ragel-6.10
CATEGORIES=	devel
MASTER_SITES=	http://www.colm.net/files/ragel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.colm.net/open-source/ragel/
COMMENT=	State machine compiler
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/ragel-guide.pdf \
		${DESTDIR}${PREFIX}/share/doc/ragel

.include "../../mk/bsd.pkg.mk"
