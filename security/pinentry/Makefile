# $NetBSD: Makefile,v 1.54 2024/03/20 15:46:37 adam Exp $

COMMENT=	Applications for entering PINs or Passphrases

CONFIGURE_ARGS+=	--disable-pinentry-fltk
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--disable-pinentry-qt5
CONFIGURE_ARGS+=	--disable-pinentry-tqt
CONFIGURE_ARGS+=	--enable-pinentry-emacs
CONFIGURE_ARGS+=	--enable-pinentry-tty

.include "../../security/pinentry/Makefile.common"

.if defined(PINENTRY_DEFAULT)
post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf pinentry-${PINENTRY_DEFAULT} pinentry
.endif

.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
