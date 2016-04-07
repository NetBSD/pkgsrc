# $NetBSD: options.mk,v 1.1 2016/04/07 14:41:34 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p7zip
PKG_SUPPORTED_OPTIONS+=	dll
PLIST_VARS+=		dll

.include "../../mk/bsd.options.mk"

PHONY: dynamic-7z-install
.if !empty(PKG_OPTIONS:Mdll)
BUILD_TARGET=		all2
PLIST.dll=		yes
CFLAGS+=		-fPIC

INSTALLATION_DIRS+=	lib/7z
INSTALLATION_DIRS+=	lib/7z/Codecs
INSTALLATION_DIRS+=	lib/7z/Formats

dynamic-7z-install:
	${INSTALL_LIB} ${WRKSRC}/bin/7z.so ${DESTDIR}${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/7z ${DESTDIR}${PREFIX}/lib/7z
	ln -f -s ${PREFIX}/lib/7z/7z ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/bin/Codecs/* \
		${DESTDIR}${PREFIX}/lib/7z/Codecs
.else
dynamic-7z-install:
.endif
