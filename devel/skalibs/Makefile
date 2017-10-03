# $NetBSD: Makefile,v 1.1 2017/10/03 00:31:39 schmonz Exp $

DISTNAME=		skalibs-2.6.0.0
MASTER_SITES=		http://skarnet.org/software/skalibs/
CATEGORIES=		devel

MAINTAINER=		cfkoch@edgebsd.org
COMMENT=		The skarnet.org C system programming library
HOMEPAGE=		http://skarnet.org/software/skalibs/
LICENSE=		isc

USE_LANGUAGES=		c
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake

PLIST_VARS+=		include-shared-objects
PLIST.include-shared-objects=	yes

CONFIGURE_ARGS+=	"--prefix=${PREFIX}"

.if "${OPSYS}" == "Darwin"
PLIST.include-shared-objects=	no
CONFIGURE_ARGS+=	"--disable-shared"
.endif

.include "../../mk/bsd.pkg.mk"
