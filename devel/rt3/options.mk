# $NetBSD: options.mk,v 1.4 2007/07/04 20:54:39 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.rt
PKG_OPTIONS_REQUIRED_GROUPS=	backend frontend
PKG_OPTIONS_GROUP.backend=	mysql oracle pgsql sqlite
PKG_OPTIONS_GROUP.frontend=	modperl1 modperl2 \
				fastcgi speedycgi
PKG_SUGGESTED_OPTIONS=	mysql fastcgi

PKG_OPTIONS_LEGACY_OPTS=	backend-mysql:mysql backend-pgsql:pgsql	\
				frontend-modperl1:modperl1		\
				frontend-modperl2:modperl2		\
				frontend-fastcgi:fastcgi

.include "../../mk/bsd.options.mk"

# Other options

RT_GROUP?=		rt
PKG_GROUPS_VARS+=	RT_GROUP
