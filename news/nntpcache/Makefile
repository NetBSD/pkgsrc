# $NetBSD: Makefile,v 1.52 2019/08/11 13:22:33 wiz Exp $

DISTNAME=		nntpcache-3.0.2
PKGREVISION=		15
CATEGORIES=		news
MASTER_SITES=		http://www.xs4all.nl/~suelette/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://iq.org/~proff/nntpcache.org/
COMMENT=		NNTP multi-server caching daemon
LICENSE=		nntpcache-license

.include "../../mk/bsd.prefs.mk"

NNTPCACHE_USER?=	news
NNTPCACHE_GROUP?=	news
PKG_GROUPS=		${NNTPCACHE_GROUP}
PKG_USERS=		${NNTPCACHE_USER}:${NNTPCACHE_GROUP}
PKG_GROUPS_VARS+=	NNTPCACHE_GROUP
PKG_USERS_VARS+=	NNTPCACHE_USER

NNTPCACHE_DIR=		${VARBASE}/spool/nntpcache

REQD_DIRS_PERMS+=	${NNTPCACHE_DIR} ${NNTPCACHE_USER} ${NNTPCACHE_GROUP} 700

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		cacheDir=${NNTPCACHE_DIR}
CONFIGURE_ENV+=		configDir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
CONFIGURE_ENV+=		nc_cv_UID=${NNTPCACHE_USER}
CONFIGURE_ENV+=		nc_cv_GID=${NNTPCACHE_GROUP}
USE_TOOLS+=		gmake perl:run
BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	nntpcache

INSTALL_MAKE_FLAGS+=	SUBDIRS="cf src filters http doc pgp contrib/newshound contrib/perlnewshound innreport scripts unixauth"
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/nntpcache
INSTALLATION_DIRS=	libexec share/doc/nntpcache share/examples/nntpcache

RCD_SCRIPTS=		nntpcached

REQD_FILES_PERMS+=	share/examples/nntpcache/VERSION	\
			${NNTPCACHE_DIR}/VERSION		\
			${NNTPCACHE_USER} ${NNTPCACHE_GROUP} 600
PKG_SYSCONFDIR_PERMS+=	${NNTPCACHE_USER} ${NNTPCACHE_GROUP} 700
CONF_FILES_PERMS+=	share/examples/nntpcache/nntpcache.access	\
			${PKG_SYSCONFDIR}/nntpcache.access		\
			${NNTPCACHE_USER} ${NNTPCACHE_GROUP} 600
CONF_FILES_PERMS+=	share/examples/nntpcache/nntpcache.config	\
			${PKG_SYSCONFDIR}/nntpcache.config		\
			${NNTPCACHE_USER} ${NNTPCACHE_GROUP} 600
CONF_FILES_PERMS+=	share/examples/nntpcache/nntpcache.servers	\
			${PKG_SYSCONFDIR}/nntpcache.servers		\
			${NNTPCACHE_USER} ${NNTPCACHE_GROUP} 600
CONF_FILES_PERMS+=	share/examples/nntpcache/pubring.asc		\
			${PKG_SYSCONFDIR}/pubring.asc			\
			${NNTPCACHE_USER} ${NNTPCACHE_GROUP} 600
CONF_FILES_PERMS+=	share/examples/nntpcache/pubring.asc		\
			${PKG_SYSCONFDIR}/pubring.asc			\
			${NNTPCACHE_USER} ${NNTPCACHE_GROUP} 600
CONF_FILES_PERMS+=	share/examples/nntpcache/pubring.pgp		\
			${PKG_SYSCONFDIR}/pubring.pgp			\
			${NNTPCACHE_USER} ${NNTPCACHE_GROUP} 600
CONF_FILES_PERMS+=	share/examples/nntpcache/spam.filter		\
			${PKG_SYSCONFDIR}/spam.filter			\
			${NNTPCACHE_USER} ${NNTPCACHE_GROUP} 600
SPECIAL_PERMS+=		libexec/unixauth ${REAL_ROOT_USER} ${NNTPCACHE_GROUP} 4554

REPLACE_PERL+=	innreport/innreport.pl innreport/innreport.pm
REPLACE_PERL+=	contrib/perlnewshound/newshound.pl

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL FAQ FAQ.html LICENSING \
		README.INN README.pam ChangeLog ${DESTDIR}${PREFIX}/share/doc/nntpcache/

.include "../../mk/bsd.pkg.mk"
