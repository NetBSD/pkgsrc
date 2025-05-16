# $NetBSD: Makefile,v 1.13 2025/05/16 22:04:06 zafer Exp $

DISTNAME=	emech-3.0.3
CATEGORIES=	chat
MASTER_SITES=	https://www.aydogan.net/distfiles/chat/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.energymech.net/
COMMENT=	IRC bot written in C
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=			YES
# The ./configure script is interactive, but selects the default values
# when given no input.
CONFIGURE_ARGS+=		< /dev/null
BUILD_TARGET=			mech

INSTALLATION_DIRS+=	bin share/examples/emech

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/energymech ${DESTDIR}${PREFIX}/bin/mech
	${INSTALL_DATA} ${WRKSRC}/sample.conf ${DESTDIR}${PREFIX}/share/examples/emech/

.include "../../mk/bsd.pkg.mk"
