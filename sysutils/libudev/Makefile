# $NetBSD: Makefile,v 1.2 2023/05/22 15:52:56 nikita Exp $

COMMENT=		Device enumeration and database of constants
CONFIGURE_ARGS+=	--disable-programs

SUBST_CLASSES+=		nogperf
SUBST_STAGE.nogperf=	pre-configure
SUBST_FILES.nogperf=	configure.ac
SUBST_SED.nogperf=	-e 's,ERROR\(.*gperf\),WARN\1,'

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../sysutils/libudev/Makefile.common"
.include "../../mk/bsd.pkg.mk"
