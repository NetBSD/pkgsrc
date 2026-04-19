# $NetBSD: options.mk,v 1.3 2026/04/19 08:57:07 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lsof
PKG_SUPPORTED_OPTIONS=		lsof-more-secure lsof-less-secure-sockets

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
