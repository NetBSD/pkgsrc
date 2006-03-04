# $NetBSD: Makefile,v 1.12 2006/03/04 21:29:35 jlam Exp $
#

DISTNAME=	p11-2.10a
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/cats/usr/harti/p11/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PDP11 emulator

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-begemot=${PREFIX:Q}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
CONFIGURE_ENV+=	ac_cv_epp_bpf=yes ac_cv_epp_tun=yes ac_cv_epp_tap=yes
.endif

# override MAKEFLAGS in the build and install stages
do-build:
	cd ${WRKSRC} && ${GMAKE} ${BUILD_TARGET} MAKEFLAGS=

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_TARGET} MAKEFLAGS=

.include "../../devel/libbegemot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
