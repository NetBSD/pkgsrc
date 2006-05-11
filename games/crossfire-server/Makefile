# $NetBSD: Makefile,v 1.1.1.1 2006/05/11 05:59:36 adam Exp $

DISTNAME=	crossfire-1.9.0
PKGNAME=	crossfire-server-1.9.0
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crossfire/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://crossfire.real-time.com/
COMMENT=	X11 multi/single player game similar to gauntlet and nethack

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}/games
CONFIGURE_ENV+=		ac_cv_path_GZIP=${GZIP_CMD:Q}

REPLACE_PERL+=	doc/include_html.pl doc/playbook/make_index.pl
REPLACE_PERL+=	doc/scripts/items-extract.pl doc/scripts/makeps.pl
REPLACE_PERL+=	doc/scripts/monster-extract.pl lib/adm/archsearch.pl
REPLACE_PERL+=	lib/adm/collect_images.pl lib/adm/map_expand.pl
REPLACE_PERL+=	lib/adm/mapslitter.pl lib/checkarch.pl
REPLACE_PERL+=	lib/collect.pl lib/util.pl utils/metaserver.pl

EGDIR=		${PREFIX}/share/examples/crossfire
CONF_FILES+=	${EGDIR:Q}/ban_file ${PKG_SYSCONFDIR:Q}/crossfire/ban_file
CONF_FILES+=	${EGDIR:Q}/dm_file ${PKG_SYSCONFDIR:Q}/crossfire/dm_file
CONF_FILES+=	${EGDIR:Q}/exp_table ${PKG_SYSCONFDIR:Q}/crossfire/exp_table
CONF_FILES+=	${EGDIR:Q}/forbid ${PKG_SYSCONFDIR:Q}/crossfire/forbid
CONF_FILES+=	${EGDIR:Q}/motd ${PKG_SYSCONFDIR:Q}/crossfire/motd
CONF_FILES+=	${EGDIR:Q}/news ${PKG_SYSCONFDIR:Q}/crossfire/news
CONF_FILES+=	${EGDIR:Q}/rules ${PKG_SYSCONFDIR:Q}/crossfire/rules
CONF_FILES+=	${EGDIR:Q}/settings ${PKG_SYSCONFDIR:Q}/crossfire/settings

.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
