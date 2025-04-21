# $NetBSD: Makefile,v 1.27 2025/04/21 21:26:46 wiz Exp $

DISTNAME=		helpdeco-2.1.3
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=helpdeco/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/helpdeco/
COMMENT=		Windows .hlp to .rtf converter

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Darwin"
CFLAGS+=		-DHAVE_STRLCPY
.endif

MAKE_ENV+=		CFLAGS=${CFLAGS:M*:Q}
BUILD_TARGET=		build
USE_TOOLS+=		gmake

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Configuring to use PREFIX.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e "s,/usr/local,${DESTDIR}${PREFIX},g"

.include "../../mk/bsd.pkg.mk"
