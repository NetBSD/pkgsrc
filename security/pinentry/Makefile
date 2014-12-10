# $NetBSD: Makefile,v 1.42 2014/12/10 10:24:21 mef Exp $
#
#PKGNAME=		${DISTNAME}
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
