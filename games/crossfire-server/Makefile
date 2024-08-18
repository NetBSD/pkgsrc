# $NetBSD: Makefile,v 1.87 2024/08/18 19:48:57 adam Exp $

DISTNAME=	crossfire-1.75.0
PKGNAME=	${DISTNAME:S/crossfire-/crossfire-server-/1}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crossfire/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	crossfire-1.71.0.arch.tar.bz2
DISTFILES+=	${DISTNAME:S/-/-maps-/}${EXTRACT_SUFX}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://crossfire.real-time.com/
COMMENT=	Multi-player graphical arcade and adventure game (server)
LICENSE=	gnu-gpl-v2

CONFIG_SHELL=		ksh
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake bash:run csh:run ksh perl:run pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-check
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/games
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
PKG_SYSCONFSUBDIR=	crossfire

PLIST_SRC=	${WRKDIR}/PLIST PLIST

REPLACE_PYTHON+=	../maps/python/CFReputation/utils/gods2factions
REPLACE_PYTHON+=	utils/cfdb_convert

PYTHON_VERSIONS_ACCEPTED=	39 # node.h is required

BUILD_DEFS+=	VARBASE

CHECK_PORTABILITY_SKIP+=	utils/get_release.in

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
REPLACE_PERL+=	utils/player_dl.pl.in
REPLACE_PERL+=	utils/mktable.script
# arch
REPLACE_BASH+=	../arch/dev/png_recompress.sh
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

SUBST_CLASSES+=		py3path
SUBST_STAGE.py3path=	pre-configure
SUBST_MESSAGE.py3path=	Fixing path to Python.
SUBST_FILES.py3path=	configure
SUBST_SED.py3path=	-e 's,"python3","python-${PYVERSSUFFIX}",g'

post-install:
	cd ${WRKDIR} && ${CP} -R arch maps ${DESTDIR}${PREFIX}/share/crossfire
	cd ${DESTDIR}${PREFIX} && \
		${FIND} share/crossfire/arch -type f -print >> ${WRKDIR}/PLIST
	cd ${DESTDIR}${PREFIX} && \
		${FIND} share/crossfire/maps -type f -print >> ${WRKDIR}/PLIST

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
