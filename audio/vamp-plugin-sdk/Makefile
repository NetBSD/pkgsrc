# $NetBSD: Makefile,v 1.13 2023/12/15 13:26:50 schmonz Exp $

DISTNAME=	vamp-plugin-sdk-2.10.0
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://code.soundsoftware.ac.uk/attachments/download/2691/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.soundsoftware.ac.uk/projects/vamp-plugin-sdk
COMMENT=	The Vamp audio analysis plugin system
LICENSE=	x11

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_CXX_FEATURES+=	c++11

SUBST_CLASSES+=		dl
SUBST_STAGE.dl=		pre-configure
SUBST_MESSAGE.dl=	Fixing usage of -ldl in pkgconfig file.
SUBST_FILES.dl+=	pkgconfig/vamp-hostsdk.pc.in
SUBST_SED.dl=		-e "s,-ldl,${DL_LIBS},g"

PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-hostsdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp-sdk.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/vamp.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=build/vamp-plugin.map

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.PHONY: post-install-darwin-fix-rpath
post-install: post-install-darwin-fix-rpath
post-install-darwin-fix-rpath:
	cd ${DESTDIR};									\
	for i in $$(${FIND} .${PREFIX}/lib -name '*.so' | ${SED} -e 's|^\./||'); do	\
	  install_name_tool -id /$$i $$i;						\
	done
.endif

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
