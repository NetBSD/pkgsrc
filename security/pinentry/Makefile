# $NetBSD: Makefile,v 1.48 2015/09/30 19:56:42 wiz Exp $

COMMENT=		Applications for entering PINs or Passphrases

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
