# $NetBSD: Makefile,v 1.50 2019/11/04 21:12:58 rillig Exp $

COMMENT=		Applications for entering PINs or Passphrases

CONFIGURE_ARGS+=	--enable-pinentry-tty
CONFIGURE_ARGS+=	--enable-pinentry-emacs
CONFIGURE_ARGS+=	--disable-pinentry-qt4
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-fltk

.include		"../../security/pinentry/Makefile.common"

.if defined(PINENTRY_DEFAULT)
post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${LN} -sf pinentry-${PINENTRY_DEFAULT} pinentry
.endif

.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
