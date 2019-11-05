# $NetBSD: Makefile,v 1.51 2019/11/05 18:55:18 rillig Exp $

PKGREVISION=		1
COMMENT=		Applications for entering PINs or Passphrases

CONFIGURE_ARGS+=	--enable-pinentry-tty
CONFIGURE_ARGS+=	--enable-pinentry-emacs
CONFIGURE_ARGS+=	--disable-pinentry-qt5
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
