# $NetBSD: Makefile,v 1.1 2023/05/10 17:39:09 nikita Exp $

COMMENT=		Device enumeration and database of constants
CONFIGURE_ARGS+=	--disable-programs

SUBST_CLASSES+=		nogperf
SUBST_STAGE.nogperf=	pre-configure
SUBST_FILES.nogperf=	configure.ac
SUBST_SED.nogperf=	-e 's,ERROR\(.*gperf\),WARN\1,'

pre-configure:
	cd ${WRKSRC} &&autoreconf -fiv

.include "../../sysutils/libudev/Makefile.common"

.include "../../mk/bsd.pkg.mk"
