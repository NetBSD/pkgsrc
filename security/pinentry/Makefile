# $NetBSD: Makefile,v 1.41 2014/12/10 02:27:43 mef Exp $
#
#PKGNAME=		${DISTNAME}
PKGREVISION=		2
COMMENT=		Applications for entering PINs or Passphrases

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
