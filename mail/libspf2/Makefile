# $NetBSD: Makefile,v 1.17 2023/06/02 15:58:46 schmonz Exp $

DISTNAME=		libspf2-1.2.11
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.libspf2.org/
COMMENT=		Implementation of the Sender Policy Framework
LICENSE=		modified-bsd OR gnu-lgpl-v2.1

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFLICTS+=		libspf_alt-[0-9]*

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "OpenBSD"
SUBST_CLASSES+=		libreplace
SUBST_STAGE.libreplace=	pre-configure
SUBST_FILES.libreplace=	src/libspf2/Makefile.in
SUBST_SED.libreplace=	-e 's|^\#pkgsrc\#||g'
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
