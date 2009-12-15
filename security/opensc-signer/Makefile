# $NetBSD: Makefile,v 1.4 2009/12/15 22:10:40 joerg Exp $

PKGNAME=		opensc-signer-${OPENSC_PKG_VERSION}
PKGREVISION=		2
COMMENT=		Opensc signer plugin for Mozilla apps
LICENSE=		gnu-lgpl-v2.1

.include "../../security/opensc/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../../security/opensc/distinfo
PATCHDIR=		${.CURDIR}/../../security/opensc/patches

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-nsplugin
CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/xulrunner/plugins
CONFIGURE_ARGS+=	--with-pinentry=${PREFIX}/bin/pinentry

do-install:
	cd ${WRKSRC}/src/signer && ${SETENV} ${MAKE_ENV} ${MAKE} \
		prefix=${DESTDIR}${PREFIX} \
		plugindir=${DESTDIR}${PREFIX}/lib/xulrunner/plugins install

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
