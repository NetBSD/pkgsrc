# $NetBSD: Makefile,v 1.37 2023/10/24 22:10:38 wiz Exp $
#

DISTNAME=		xorp-1.6
PKGREVISION=		9
CATEGORIES=		net
MASTER_SITES=		http://www.xorp.org/releases/1.6/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.xorp.org/
COMMENT=		The eXtensible Open Router Platform

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake flex
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl:Q}

# The xorp people insist on their own PREFIX.
# See http://www.xorp.org/bugzilla/show_bug.cgi?id=91
#
GNU_CONFIGURE_PREFIX=	${PREFIX}/xorp

# Test target require bash and python (really it, not python2.4 and so on).
TEST_TARGET=		check

pre-build:
	cd ${WRKSRC}/policy && ${MAKE} lex
	cd ${WRKSRC}/policy/backend && ${MAKE} lex
	cd ${WRKSRC}/policy/test && ${MAKE} lex
	cd ${WRKSRC}/rtrmgr && ${MAKE} lex

# This used to be set for clang only, but it's needed for gcc as well
# these days. See PR 36974; also there are other warnings with gcc48.
BUILDLINK_TRANSFORM+=	rm:-Werror

# configure sets the template depth limit to 25 but it is too small
BUILDLINK_TRANSFORM+=	opt:-ftemplate-depth-25:-ftemplate-depth=50

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
