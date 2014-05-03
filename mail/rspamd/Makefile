# $NetBSD: Makefile,v 1.5 2014/05/03 13:14:38 alnsn Exp $

DISTNAME=	rspamd-0.6.8
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	https://rspamd.com/downloads/

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://www.rspamd.com/
COMMENT=	Fast, free and open-source spam filtering system
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_TOOLS+=	perl pkg-config

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/rspamd

PKG_SYSCONFSUBDIR=	rspamd
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

CMAKE_ARGS+=    -DMANDIR:PATH=${PREFIX}/${PKGMANDIR}
CMAKE_ARGS+=    -DCONFDIR:PATH=${EGDIR}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/lua
MAKE_DIRS+=	${PKG_SYSCONFDIR}/lua/regexp

CONF_FILES=	${EGDIR}/2tld.inc ${PKG_SYSCONFDIR}/2tld.inc
CONF_FILES+=	${EGDIR}/composites.conf ${PKG_SYSCONFDIR}/composites.conf
CONF_FILES+=	${EGDIR}/logging.conf ${PKG_SYSCONFDIR}/logging.conf
CONF_FILES+=	${EGDIR}/lua/hfilter.lua ${PKG_SYSCONFDIR}/lua/hfilter.lua
CONF_FILES+=	${EGDIR}/lua/regexp/drugs.lua ${PKG_SYSCONFDIR}/lua/regexp/drugs.lua
CONF_FILES+=	${EGDIR}/lua/regexp/fraud.lua ${PKG_SYSCONFDIR}/lua/regexp/fraud.lua
CONF_FILES+=	${EGDIR}/lua/regexp/headers.lua ${PKG_SYSCONFDIR}/lua/regexp/headers.lua
CONF_FILES+=	${EGDIR}/lua/regexp/lotto.lua ${PKG_SYSCONFDIR}/lua/regexp/lotto.lua
CONF_FILES+=	${EGDIR}/lua/rspamd.classifiers.lua ${PKG_SYSCONFDIR}/lua/rspamd.classifiers.lua
CONF_FILES+=	${EGDIR}/lua/rspamd.lua ${PKG_SYSCONFDIR}/lua/rspamd.lua
CONF_FILES+=	${EGDIR}/metrics.conf ${PKG_SYSCONFDIR}/metrics.conf
CONF_FILES+=	${EGDIR}/modules.conf ${PKG_SYSCONFDIR}/modules.conf
CONF_FILES+=	${EGDIR}/options.conf ${PKG_SYSCONFDIR}/options.conf
CONF_FILES+=	${EGDIR}/rspamd.conf ${PKG_SYSCONFDIR}/rspamd.conf
CONF_FILES+=	${EGDIR}/statistic.conf ${PKG_SYSCONFDIR}/statistic.conf
CONF_FILES+=	${EGDIR}/surbl-whitelist.inc ${PKG_SYSCONFDIR}/surbl-whitelist.inc
CONF_FILES+=	${EGDIR}/workers.conf ${PKG_SYSCONFDIR}/workers.conf

post-extract:
	${FIND} ${WRKSRC}/conf -type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${WRKSRC}/conf -type f -exec ${CHMOD} ${DOCMODE} {} \;

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
