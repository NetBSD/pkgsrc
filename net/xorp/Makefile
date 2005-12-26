# $NetBSD: Makefile,v 1.13 2005/12/26 23:39:33 schmonz Exp $
#

DISTNAME=		xorp-1.0
PKGREVISION=	1
CATEGORIES=		net
MASTER_SITES=		http://www.xorp.org/releases/1.0/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.xorp.org/
COMMENT=		The eXtensible Open Router Platform

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

# The xorp people insist on their own PREFIX.
# See http://www.xorp.org/bugzilla/show_bug.cgi?id=91
GNU_CONFIGURE_PREFIX=	${LOCALBASE}/xorp

TEST_TARGET=		check

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
