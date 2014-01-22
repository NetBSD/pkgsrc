# $NetBSD: options.mk,v 1.3 2014/01/22 09:18:40 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fop
PKG_SUPPORTED_OPTIONS=	doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
PLIST_SRC+=	${PKGDIR}/PLIST.docs
.endif

post-extract: fop-ttfreader
.if empty(PKG_OPTIONS:Mdoc)
.for subdir in docs javadocs
	cd ${WRKSRC} && ${RM} -rf ${subdir}
.endfor
.endif
