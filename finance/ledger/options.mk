# $NetBSD: options.mk,v 1.2 2017/09/06 21:08:09 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ledger
PKG_SUPPORTED_OPTIONS+=	python
PKG_SUGGESTED_OPTIONS+=	python

PLIST_VARS+=		python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=		-DUSE_PYTHON:BOOL=TRUE
PLIST.python=		yes
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
PYTHON_VERSIONS_ACCEPTED=	27 # as of 3.1.1
.include "../../devel/py-boost/buildlink3.mk"
.endif
