# $NetBSD: Makefile,v 1.9 2020/03/23 09:27:34 tnn Exp $
#

DISTNAME=		libedit-20191231-3.1
PKGNAME=		editline-3.1.20191231
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://thrysoee.dk/editline/

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://www.thrysoee.dk/editline/
COMMENT=		NetBSD Editline library (libedit) for generic line editing
LICENSE=		modified-bsd

PKGCONFIG_OVERRIDE+=	libedit.pc.in

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		automake autoreconf
CONFIGURE_ARGS+=	--enable-widec

.include "../../mk/bsd.prefs.mk"

pre-configure:
.if ${OPSYS} == "SunOS" && !exists(/usr/include/err.h)
	${CP} ${FILESDIR}/err.h ${BUILDLINK_DIR}/include
.endif
	cd ${WRKSRC} && autoreconf -fiv

PKG_OPTIONS_VAR=	PKG_OPTIONS.editline
PKG_SUPPORTED_OPTIONS+=	doc
PKG_SUGGESTED_OPTIONS+=	# empty; conflicts with devel/readline

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	doc
.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=	yes
.endif

post-extract:
.if !empty(PKG_OPTIONS:Mdoc)
.else
	${ECHO} "" > ${WRKSRC}/doc/Makefile.am
.endif

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
