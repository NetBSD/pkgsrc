# $NetBSD: Makefile,v 1.43 2015/01/15 20:48:33 wiz Exp $
#
#PKGNAME=		${DISTNAME}
PKGREVISION=		1
COMMENT=		Applications for entering PINs or Passphrases

CONFIGURE_ARGS+=	--enable-pinentry-tty

.include		"../../security/pinentry/Makefile.common"

.include "options.mk"

.if defined(PINENTRY_DEFAULT)
post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf pinentry-${PINENTRY_DEFAULT} pinentry
.endif

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
