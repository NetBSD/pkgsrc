# $NetBSD: options.mk,v 1.3 2020/05/01 11:48:26 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ledger
PKG_SUPPORTED_OPTIONS+=	python
PKG_SUGGESTED_OPTIONS+=	python

PLIST_VARS+=		python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=		-DUSE_PYTHON:BOOL=TRUE
PLIST.python=		yes
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
.include "../../devel/py-boost/buildlink3.mk"
.endif
