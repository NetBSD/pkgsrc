# $NetBSD: Makefile,v 1.21 2008/01/18 05:08:52 tnn Exp $
#

DISTNAME=		xorp-1.4
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.xorp.org/releases/1.4/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.xorp.org/
COMMENT=		The eXtensible Open Router Platform

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl:Q}

# The xorp people insist on their own PREFIX.
# See http://www.xorp.org/bugzilla/show_bug.cgi?id=91
#
GNU_CONFIGURE_PREFIX=	${PREFIX}/xorp

TEST_TARGET=		check

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
