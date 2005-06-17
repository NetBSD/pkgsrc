# $NetBSD: Makefile,v 1.49 2005/06/17 16:27:58 jlam Exp $

DISTNAME=		magicpoint-1.10a
PKGREVISION=		7
#DISTNAME=		magicpoint-1.11b.tar.gz
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://sh.wide.ad.jp/WIDE/free-ware/mgp/ \
			ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=		itojun@itojun.org
HOMEPAGE=		http://member.wide.ad.jp/wg/mgp/
COMMENT=		X11 based presentation tool

CONFLICTS=		mgp-[0-9]*

GNU_CONFIGURE=		yes
USE_IMAKE=		yes
USE_PERL5=		build

PKG_OPTIONS_VAR=	PKG_OPTIONS.magicpoint
PKG_SUPPORTED_OPTIONS=	freetype vflib xft2
PKG_SUGGESTED_OPTIONS=	xft2

.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--enable-freetype-charset16
CONFIGURE_ARGS+=	--enable-locale
CONFIGURE_ARGS+=	--enable-gif
CONFIGURE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}
CONFIGURE_ENV+=		mgp_cv_path_perl=${TOOLS_PERL5:Q}

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
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${s}
.endfor

pre-install:
	${SED} -e "/^%% Default.*${PKG_OPTIONS}\./,/^%%%/s/^%% %/%/" \
		${WRKSRC}/sample/default.mgp.template > \
		${WRKSRC}/sample/default.mgp

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mgp
	cd ${WRKSRC};							\
		for f in COPYRIGHT COPYRIGHT.jp FAQ README README.fonts	\
			README.fonts.jp README.lang SYNTAX USAGE USAGE.jp; do \
			${INSTALL_DATA} $$f ${PREFIX}/share/doc/mgp;	\
		done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mgp
	cd ${WRKSRC}/sample;						\
		for f in README* *.jpg *.eps *.mgp *.xbm mgprc-sample; do \
			${INSTALL_DATA} $$f ${PREFIX}/share/examples/mgp; \
		done

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
