# $NetBSD: Makefile,v 1.5 2019/11/03 10:39:30 rillig Exp $

DISTNAME=		skalibs-2.8.1.0
CATEGORIES=		devel
MASTER_SITES=		http://skarnet.org/software/skalibs/

MAINTAINER=		cfkoch@edgebsd.org
HOMEPAGE=		http://skarnet.org/software/skalibs/
COMMENT=		The skarnet.org C system programming library
LICENSE=		isc

USE_LANGUAGES=		c
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

PLIST_VARS+=			include-shared-objects
.if "${OPSYS}" == "Darwin"
CONFIGURE_ARGS+=		"--disable-shared"
.else
PLIST.include-shared-objects=	yes
.endif

.include "../../mk/bsd.pkg.mk"
