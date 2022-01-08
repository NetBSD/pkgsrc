# $NetBSD: Makefile,v 1.8 2022/01/08 15:19:21 tsutsui Exp $

PKGNAME=	${RUBY_PKGPREFIX}-mikutter-plugins-twitter-5.0
DIST_SUBDIR=	mikutter-plugins
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mikutter/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/mikutter/twitter_bootstrap
COMMENT=	Plugins for mikutter to use Twitter
LICENSE=	mit

PLUGIN_DISTNAME+=	api_request_file_cache-1.0
# XXX direct message doesn't work after Twitter API changes
#PLUGIN_DISTNAME+=	direct_message-1.1
PLUGIN_DISTNAME+=	followingcontrol-2.0
PLUGIN_DISTNAME+=	home_timeline-2.0
PLUGIN_DISTNAME+=	list-2.1
PLUGIN_DISTNAME+=	list_for_profile-2.0
PLUGIN_DISTNAME+=	list_settings-2.1
PLUGIN_DISTNAME+=	mentions-1.0
PLUGIN_DISTNAME+=	message_detail_view-2.0
PLUGIN_DISTNAME+=	message_favorite-1.0
PLUGIN_DISTNAME+=	message_retweet-2.0
PLUGIN_DISTNAME+=	ratelimit-1.0
PLUGIN_DISTNAME+=	rest-1.1
PLUGIN_DISTNAME+=	saved_search-1.1
PLUGIN_DISTNAME+=	streaming-2.3
PLUGIN_DISTNAME+=	twitter-2.1
PLUGIN_DISTNAME+=	twitter_activity-1.0
PLUGIN_DISTNAME+=	twitter_datasource-1.1
PLUGIN_DISTNAME+=	twitter_settings-1.2
PLUGIN_DISTNAME+=	user_detail_view-2.0

DISTFILES=
.for plugin in ${PLUGIN_DISTNAME}
DISTFILES+=	${plugin}${EXTRACT_SUFX}
SITES.${plugin}${EXTRACT_SUFX}=	-${MASTER_SITES:=${plugin:C/-[^-]*$//}/archive/v${plugin:C/^.*-//}${EXTRACT_SUFX}}
.endfor

DEPENDS+=	${RUBY_PKGPREFIX}-mikutter>=5.0.0:../../net/mikutter
DEPENDS+=	${RUBY_PKGPREFIX}-twitter-text-simpleidn>=3.0.0.0:../../net/ruby-twitter-text-simpleidn

USE_TOOLS+=	pax

EXTRACT_DIR=	${WRKDIR}/plugin
WRKSRC=		${EXTRACT_DIR}

PLUGINDIR=		vendor/plugin
INSTALLATION_DIRS+=	share/mikutter/{PLUGINDIR}

NO_BUILD=	yes

post-extract:
.for plugin in ${PLUGIN_DISTNAME}
	# drop version tag strings from plugin names
	(cd ${WRKSRC} && ${MV} ${plugin} ${plugin:C/-[^-]*$//})
.endfor

do-install:
	(cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' . \
	    ${DESTDIR}${PREFIX}/share/mikutter/${PLUGINDIR})

.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
