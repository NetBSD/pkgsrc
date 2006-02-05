# $NetBSD: Makefile,v 1.15 2006/02/05 23:10:33 joerg Exp $
#

DISTNAME=		xorp-1.0
PKGREVISION=	2
CATEGORIES=		net
MASTER_SITES=		http://www.xorp.org/releases/1.0/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.xorp.org/
COMMENT=		The eXtensible Open Router Platform

BROKEN_IN=		pkgsrc-2005Q4

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

# The xorp people insist on their own PREFIX.
# See http://www.xorp.org/bugzilla/show_bug.cgi?id=91
GNU_CONFIGURE_PREFIX=	${LOCALBASE}/xorp

TEST_TARGET=		check

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
