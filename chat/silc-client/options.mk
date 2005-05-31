# $NetBSD: options.mk,v 1.2 2005/05/31 10:01:36 dillo Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.silc-client
PKG_SUPPORTED_OPTIONS=	debug inet6 perl
PKG_SUGGESTED_OPTIONS=	inet6 perl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mperl)
CONFIGURE_ARGS+=	--with-perl-lib=${PREFIX}/lib/${PKGBASE}/perl5
PERL5_REQD+=		5.6.1nb10
.include "../../lang/perl5/buildlink3.mk"
DEPENDS+=		p5-File-MMagic>=1.20:../../misc/p5-File-MMagic
PLIST_SRC+=		${PKGDIR}/PLIST.perl
PLIST_SRC+=		${WRKDIR}/PLIST.perl
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif
