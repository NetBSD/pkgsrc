# $NetBSD: Makefile,v 1.47 2015/08/18 07:31:17 wiz Exp $

COMMENT=		Applications for entering PINs or Passphrases
PKGREVISION=		2

CONFIGURE_ARGS+=	--enable-pinentry-tty
CONFIGURE_ARGS+=        --enable-pinentry-emacs
CONFIGURE_ARGS+=        --disable-pinentry-qt4
CONFIGURE_ARGS+=        --disable-pinentry-gnome3
CONFIGURE_ARGS+=        --disable-pinentry-gtk2

.include		"../../security/pinentry/Makefile.common"

.if defined(PINENTRY_DEFAULT)
post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf pinentry-${PINENTRY_DEFAULT} pinentry
.endif

.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
