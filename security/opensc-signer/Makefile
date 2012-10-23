# $NetBSD: Makefile,v 1.9 2012/10/23 18:16:38 asau Exp $

PKGNAME=		opensc-signer-${OPENSC_PKG_VERSION}
PKGREVISION=		1
COMMENT=		Opensc signer plugin for Mozilla apps
LICENSE=		gnu-lgpl-v2.1

.include "../../security/opensc/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../security/opensc/distinfo
PATCHDIR=		${.CURDIR}/../../security/opensc/patches

CONFIGURE_ARGS+=	--enable-nsplugin
CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/xulrunner/plugins
CONFIGURE_ARGS+=	--with-pinentry=${PREFIX}/bin/pinentry

LDFLAGS.SunOS+=		-liconv

do-install:
	cd ${WRKSRC}/src/signer && ${SETENV} ${MAKE_ENV} ${MAKE} \
		prefix=${DESTDIR}${PREFIX} \
		plugindir=${DESTDIR}${PREFIX}/lib/xulrunner/plugins install

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
