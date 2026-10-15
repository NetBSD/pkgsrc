# $NetBSD: Makefile,v 1.21 2026/10/15 19:51:20 tm Exp $

DISTNAME=		libspf2-1.2.11
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.libspf2.net/
COMMENT=		Implementation of the Sender Policy Framework
LICENSE=		modified-bsd OR gnu-lgpl-v2.1

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFLICTS+=		libspf_alt-[0-9]*

LDFLAGS.Darwin+=	-lresolv

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "OpenBSD"
SUBST_CLASSES+=		libreplace
SUBST_STAGE.libreplace=	pre-configure
SUBST_FILES.libreplace=	src/libspf2/Makefile.in
SUBST_SED.libreplace=	-e 's|^\#pkgsrc\#||g'
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
