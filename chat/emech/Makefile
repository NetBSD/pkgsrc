# $NetBSD: Makefile,v 1.9 2012/10/03 00:02:35 asau Exp $
#

DISTNAME=	emech-3.0.2
CATEGORIES=	chat
MASTER_SITES=	http://www.energymech.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.energymech.net/
COMMENT=	IRC bot written in C

HAS_CONFIGURE=			YES
# The ./configure script is interactive, but selects the default values
# when given no input.
CONFIGURE_ARGS+=		< /dev/null
BUILD_TARGET=			mech

INSTALLATION_DIRS+= bin share/examples/emech

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/energymech ${DESTDIR}${PREFIX}/bin/mech
	${INSTALL_DATA} ${WRKSRC}/sample.conf ${DESTDIR}${PREFIX}/share/examples/emech/

.include "../../mk/bsd.pkg.mk"
