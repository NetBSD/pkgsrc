# $NetBSD: options.mk,v 1.1.1.1 2010/12/24 07:21:08 kefren Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.amavis-perl
PKG_SUPPORTED_OPTIONS=	milter

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmilter)
DEPENDS+=	sendmail>=8.12.9nb1:../../mail/sendmail

# XXX Milter needs pthreads, and configure fails looking for it
# because ${PREFIX}/include is not available in the include path.
CONFIGURE_ENV+=	CFLAGS="-I${PREFIX}/include"
.include "../../mk/pthread.buildlink3.mk"

CONFIGURE_ARGS+=--enable-milter
CONFIGURE_ARGS+=--with-milter-libs=${PREFIX}/lib
CONFIGURE_ARGS+=--with-milter-includes=${PREFIX}/include
.else
CONFIGURE_ARGS+=--enable-smtp --with-smtp-port=${SMTPPORT:Q}
PLIST_SRC+=	${PKGDIR}/PLIST.nomilter
.endif
