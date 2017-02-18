# $NetBSD: options.mk,v 1.1 2017/02/18 05:48:51 riastradh Exp $

PKG_SUPPORTED_OPTIONS+=	python
PKG_OPTIONS_VAR=	PKG_OPTIONS.ledger
PLIST_VARS+=		python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=		-DUSE_PYTHON:BOOL=TRUE
PLIST.python=		yes
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
.include "../../devel/py-boost/buildlink3.mk"
.endif
