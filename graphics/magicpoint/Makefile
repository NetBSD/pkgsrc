# $NetBSD: Makefile,v 1.41 2004/11/30 17:29:30 taca Exp $

DISTNAME=		magicpoint-1.10a
PKGREVISION=		4
#DISTNAME=		magicpoint-1.11b.tar.gz
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://sh.wide.ad.jp/WIDE/free-ware/mgp/ \
			ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=		itojun@itojun.org
HOMEPAGE=		http://www.Mew.org/mgp/
COMMENT=		X11 based presentation tool

CONFLICTS=		mgp-[0-9]*

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_IMAKE=		yes
USE_PERL5=		build

PKG_OPTIONS_VAR=	PKG_OPTIONS.magicpoint
PKG_DEFAULT_OPTIONS+=	xft2
PKG_SUPPORTED_OPTIONS+=	freetype vflib xft2

.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--enable-freetype-charset16
CONFIGURE_ARGS+=	--enable-locale
CONFIGURE_ARGS+=	--enable-gif
CONFIGURE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}

MGP_RENDERING_ENGINES=	freetype	graphics/freetype-lib \
			xft2		fonts/Xft2 \
			vflib		print/ja-vflib-lib

# We need to perform the steps normally done by ``xmkmf -a'' since some
# files need to be created before ``make depend''.
#
XMKMF=			${XMKMF_CMD} ${XMKMF_FLAGS}

MGP_PRE_STAGE=		ctlwords.h grammar.c scanner.c tokdefs.h \
			Makefiles includes depend

post-configure:
.for s in ${MGP_PRE_STAGE}
	cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} $s
.endfor

pre-install:
	${SED} -e "/^%% Default.*${MGP_RENDERING_ENGINE}\./,/^%%%/s/^%% %/%/" \
		${WRKSRC}/sample/default.mgp.template > \
		${WRKSRC}/sample/default.mgp

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mgp
	cd ${WRKSRC}; \
	${INSTALL_DATA} COPYRIGHT COPYRIGHT.jp FAQ \
		README README.fonts README.fonts.jp README.lang \
		SYNTAX USAGE USAGE.jp ${PREFIX}/share/doc/mgp
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mgp
	cd ${WRKSRC}/sample; \
	${INSTALL_DATA} README* *.jpg *.eps *.mgp *.xbm mgprc-sample \
		${PREFIX}/share/examples/mgp

.for engine pkg in ${MGP_RENDERING_ENGINES}
.  if !empty(PKG_OPTIONS:M${engine})
CONFIGURE_ARGS+=	--enable-${engine}
.include "../../${pkg}/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-${engine}
.  endif
.endfor

.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
