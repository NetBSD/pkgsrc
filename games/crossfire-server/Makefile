# $NetBSD: Makefile,v 1.38 2018/08/16 18:54:45 adam Exp $

DISTNAME=	crossfire-1.11.0
PKGNAME=	crossfire-server-1.11.0
PKGREVISION=	29
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crossfire/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${DISTNAME}.arch.tar.gz ${DISTNAME}.maps.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://crossfire.real-time.com/
COMMENT=	X11 multi/single player game similar to gauntlet and nethack

PKG_SYSCONFSUBDIR=	crossfire

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl:run bash:run csh:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/games
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ENV+=		ac_cv_path_GZIP=${GZIP_CMD:Q}
PLIST_SRC=		${WRKDIR}/PLIST PLIST

INSTALLATION_DIRS=	share/crossfire/arch
INSTALLATION_DIRS+=	share/crossfire/maps

# crossfire
REPLACE_BASH+=	utils/crossloop.web.in
REPLACE_PERL+=	doc/include_html.pl
REPLACE_PERL+=	doc/playbook/make_index.pl
REPLACE_PERL+=	doc/scripts/items-extract.pl
REPLACE_PERL+=	doc/scripts/makeps.pl
REPLACE_PERL+=	doc/scripts/monster-extract.pl
REPLACE_PERL+=	lib/adm/archsearch.pl
REPLACE_PERL+=	lib/adm/collect_images.pl
REPLACE_PERL+=	lib/adm/map_expand.pl
REPLACE_PERL+=	lib/adm/mapslitter.pl
REPLACE_PERL+=	lib/checkarch.pl
REPLACE_PERL+=	lib/collect.pl
REPLACE_PERL+=	lib/util.pl
REPLACE_PERL+=	utils/metaserver.pl
REPLACE_PERL+=	utils/player_dl.pl.in
REPLACE_PERL+=	utils/metaserver.pl.in
REPLACE_PERL+=	utils/mktable.script
REPLACE_PERL+=	lib/adm/map_info
# arch
REPLACE_CSH+=	../arch/dev/xpmtopng
REPLACE_CSH+=	../arch/dev/merge.csh
REPLACE_CSH+=	../arch/dev/scripts/updatearch
REPLACE_PERL+=	../arch/dev/scripts/update_armor.pl
REPLACE_PERL+=	../arch/dev/scripts/update_body.pl
REPLACE_PERL+=	../arch/dev/scripts/update_monster.pl
REPLACE_PERL+=	../arch/dev/scripts/update_object.pl
REPLACE_PERL+=	../arch/dev/scripts/update_shield.pl
REPLACE_PERL+=	../arch/dev/split-png-linux.pl
REPLACE_PERL+=	../arch/dev/splitter-png.pl
REPLACE_PERL+=	../arch/dev/splitter.pl
# maps
REPLACE_BASH+=	../maps/brest/pshops/pshop_copier
REPLACE_PERL+=	../maps/Info/combine.pl
REPLACE_PERL+=	../maps/Info/map_sed.pl
REPLACE_PERL+=	../maps/Info/rewrite_exits.pl
REPLACE_PERL+=	../maps/Info/rewrite_styles.pl
REPLACE_PERL+=	../maps/Info/update_apart.pl
REPLACE_PERL+=	../maps/Info/update_exits.pl

EGDIR=		${PREFIX}/share/examples/crossfire
CONF_FILES+=	${EGDIR}/ban_file ${PKG_SYSCONFDIR}/ban_file
CONF_FILES+=	${EGDIR}/dm_file ${PKG_SYSCONFDIR}/dm_file
CONF_FILES+=	${EGDIR}/exp_table ${PKG_SYSCONFDIR}/exp_table
CONF_FILES+=	${EGDIR}/forbid ${PKG_SYSCONFDIR}/forbid
CONF_FILES+=	${EGDIR}/metaserver2 ${PKG_SYSCONFDIR}/metaserver2
CONF_FILES+=	${EGDIR}/motd ${PKG_SYSCONFDIR}/motd
CONF_FILES+=	${EGDIR}/news ${PKG_SYSCONFDIR}/news
CONF_FILES+=	${EGDIR}/rules ${PKG_SYSCONFDIR}/rules
CONF_FILES+=	${EGDIR}/settings ${PKG_SYSCONFDIR}/settings

post-install:
	cd ${WRKDIR} && cp -R arch maps ${DESTDIR}${PREFIX}/share/crossfire
	cd ${DESTDIR}${PREFIX} && \
		${FIND} share/crossfire/arch -type f -print >> ${WRKDIR}/PLIST
	cd ${DESTDIR}${PREFIX} && \
		${FIND} share/crossfire/maps -type f -print >> ${WRKDIR}/PLIST

.include "options.mk"

.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
