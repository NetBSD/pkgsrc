# $NetBSD: Makefile,v 1.19 2012/09/15 10:06:06 obache Exp $
#

DISTNAME=	nfdump-1.6.6
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nfdump/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nfdump.sourceforge.net/
COMMENT=	Tools to collect and process netflow data

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
TEST_TARGET=	test
USE_TOOLS+=	lex yacc

PKG_OPTIONS_VAR=	PKG_OPTIONS.nfdump
PKG_SUPPORTED_OPTIONS=	nfdump-ftconv nfdump-sflow nfdump-nfprofile
.include "../../mk/bsd.options.mk"

PLIST_SRC=		${PKGDIR}/PLIST

.if !empty(PKG_OPTIONS:Mnfdump-ftconv)
CONFIGURE_ARGS+=	--enable-ftconv
CONFIGURE_ARGS+=	--with-ftpath=${BUILDLINK_PREFIX.flow-tools}
PLIST_SRC+=		${PKGDIR}/PLIST.ftconv
.  include "../../net/flow-tools/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnfdump-sflow)
CONFIGURE_ARGS+=	--enable-sflow
PLIST_SRC+=		${PKGDIR}/PLIST.sflow
.endif

.if !empty(PKG_OPTIONS:Mnfdump-nfprofile)
CONFIGURE_ARGS+=	--enable-nfprofile
PLIST_SRC+=		${PKGDIR}/PLIST.nfprofile
.  include "../../databases/rrdtool/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
