# $NetBSD: options.mk,v 1.1 2010/04/30 06:53:06 sbd Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lsof
PKG_SUPPORTED_OPTIONS=		lsof-more-secure lsof-less-secure-sockets

.if defined(LSOF_MORE_SECURE)
.  if !empty(LSOF_MORE_SECURE:M1)
PKG_LEGACY_OPTIONS+=	lsof-more-secure
PKG_OPTIONS_DEPRECATED_WARNINGS+=	"Deprecated variable LSOF_MORE_SECURE set to 1, use PKG_OPTIONS.lsof+=lsof-more-secure instead."
.  elif !empty(LSOF_MORE_SECURE:M0)
PKG_LEGACY_OPTIONS+=	-lsof-more-secure
PKG_OPTIONS_DEPRECATED_WARNINGS+=	"Deprecated variable LSOF_MORE_SECURE set to 0, use PKG_OPTIONS.lsof+=-lsof-more-secure instead."
.  endif
.endif

.if defined(LSOF_LESS_SECURE_SOCKETS)
.  if !empty(LSOF_LESS_SECURE_SOCKETS:M1)
PKG_LEGACY_OPTIONS+=	lsof-less-secure-sockets
PKG_OPTIONS_DEPRECATED_WARNINGS+=	"Deprecated variable LSOF_LESS_SECURE_SOCKETS set to 1, use PKG_OPTIONS.lsof+=lsof-less-secure-sockets instead."
.  elif !empty(LSOF_LESS_SECURE_SOCKETS:M0)
PKG_LEGACY_OPTIONS+=	-lsof-less-secure-sockets
PKG_OPTIONS_DEPRECATED_WARNINGS+=	"Deprecated variable LSOF_LESS_SECURE_SOCKETS set to 0, use PKG_OPTIONS.lsof+=lsof-less-secure-sockets instead."
.  endif
.endif

.include "../../mk/bsd.options.mk"

## Emulate what ./Customize does.
post-configure:
	${RUN} cd ${WRKSRC}; ${MV} -f machine.h machine.h.orig ;	\
	${CAT} machine.h.orig > machine.h ;				\
	${ECHO} "#undef HASSECURITY" >> machine.h ;			\
	${ECHO} "#undef HASNOSOCKSECURITY" >> machine.h ;
.if !empty(PKG_OPTIONS:Mlsof-more-secure)
	${ECHO} "#define HASSECURITY 1" >> ${WRKSRC}/machine.h
.  if !empty(PKG_OPTIONS:Mlsof-less-secure-sockets)
	${ECHO} "#define HASNOSOCKSECURITY 1" >> ${WRKSRC}/machine.h
.  endif
.endif
