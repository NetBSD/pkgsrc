# $NetBSD: Makefile,v 1.19 2005/12/05 20:51:03 rillig Exp $
#

DISTNAME=		helpdeco-2.1.3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=helpdeco/}

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/helpdeco/
COMMENT=		Windows .hlp to .rtf converter

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
CFLAGS+=		-DHAVE_STRLCPY
.endif

MAKE_ENV+=		CFLAGS=${CFLAGS:M*:Q}
BUILD_TARGET=		build
USE_TOOLS+=		gmake

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	"Configuring to use PREFIX."
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},g"

.include "../../mk/bsd.pkg.mk"
