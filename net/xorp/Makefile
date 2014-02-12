# $NetBSD: Makefile,v 1.29 2014/02/12 23:18:27 tron Exp $
#

DISTNAME=		xorp-1.6
PKGREVISION=		4
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

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
BUILDLINK_TRANSFORM+=	rm:-Werror
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
