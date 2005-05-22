# $NetBSD: Makefile,v 1.12 2005/05/22 20:08:26 jlam Exp $
#

DISTNAME=		xorp-1.0
PKGREVISION=	1
CATEGORIES=		net
MASTER_SITES=		http://www.xorp.org/releases/1.0/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.xorp.org/
COMMENT=		The eXtensible Open Router Platform

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

# The xorp people insist on their own PREFIX.
# See http://www.xorp.org/bugzilla/show_bug.cgi?id=91
GNU_CONFIGURE_PREFIX=	${LOCALBASE}/xorp

TEST_TARGET=		check

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
