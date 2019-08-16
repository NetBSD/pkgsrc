# $NetBSD: database.mk,v 1.3 2019/08/16 10:54:51 wiz Exp $
#
# This Makefile fragment is intended to be included by packages that install
# dconf database.  It takes care of update the corresponding databases
# at (de)installation time.
#

.if !defined(DCONF_DATABASE_MK)
DCONF_DATABASE_MK=	# defined

DCONF=			${PREFIX}/bin/dconf

FILES_SUBST+=		DCONF=${DCONF:Q}
INSTALL_TEMPLATES+=	../../devel/dconf/files/database.tmpl
DEINSTALL_TEMPLATES+=	../../devel/dconf/files/database.tmpl

TOOLS_NOOP+=		dconf

DEPENDS+=		dconf-[0-9]*:../../devel/dconf

.endif			# DCONF_DATABASE_MK
