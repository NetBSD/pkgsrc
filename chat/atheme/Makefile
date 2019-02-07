# $NetBSD: Makefile,v 1.16 2019/02/07 14:29:20 nia Exp $
#

DISTNAME=	atheme-7.2.9
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=atheme/}
EXTRACT_SUFX=	.tar.bz2
GITHUB_PROJECT=	atheme
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://atheme.github.io/atheme.html
COMMENT=	Flexible IRC services system with proven scalability
LICENSE=	isc

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt msgmerge xgettext
BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	atheme
EGDIR=			${PREFIX}/share/examples/atheme
DOC_FILES=		INSTALL README.md
MAKE_JOBS_SAFE=		NO
ATHEME_USER?=		atheme
ATHEME_GROUP?=		atheme

RCD_SCRIPTS+=		atheme

PKG_USERS_VARS=		ATHEME_USER
PKG_GROUPS_VARS=	ATHEME_GROUP
PKG_GROUPS=		${ATHEME_GROUP}
PKG_USERS=		${ATHEME_USER}:${ATHEME_GROUP}

PKG_GECOS.${ATHEME_USER}=	atheme user

FILES_SUBST+=		ATHEME_USER=${ATHEME_USER}
FILES_SUBST+=		ATHEME_GROUP=${ATHEME_GROUP}

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		posixcrypt
.if ${OPSYS} != "Darwin"
PLIST.posixcrypt=	yes
.endif

CFLAGS.SunOS+=		-Dfaultcode_t=foo_faultcode_t -Dboolean_t=foo_boolean_t

CONFIGURE_ARGS+=	--with-libmowgli=no # use internal libmowgli
CONFIGURE_ARGS+=	--enable-reproducible-builds
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--enable-fhs-paths
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONF_FILES_PERMS=	${EGDIR}/atheme.conf.example \
			${PKG_SYSCONFDIR}/atheme.conf \
			${ATHEME_USER} ${ATHEME_GROUP} 0660
CONF_FILES_PERMS+=	${EGDIR}/atheme.cron.example \
			${PKG_SYSCONFDIR}/atheme.cron \
			${ATHEME_USER} ${ATHEME_GROUP} 0660
CONF_FILES_PERMS+=	${EGDIR}/atheme.motd.example \
			${PKG_SYSCONFDIR}/atheme.motd \
			${ATHEME_USER} ${ATHEME_GROUP} 0660
CONF_FILES_PERMS+=	${EGDIR}/atheme.conf.operserv-example \
			${PKG_SYSCONFDIR}/atheme.conf.operserv \
			${ATHEME_USER} ${ATHEME_GROUP} 0660
CONF_FILES_PERMS+=	${EGDIR}/atheme.conf.userserv-example \
			${PKG_SYSCONFDIR}/atheme.conf.userserv \
			${ATHEME_USER} ${ATHEME_GROUP} 0660

MAKE_DIRS_PERMS+=	${VARBASE}/atheme \
			${ATHEME_USER} ${ATHEME_GROUP} 0770
MAKE_DIRS_PERMS+=	${VARBASE}/log/atheme \
			${ATHEME_USER} ${ATHEME_GROUP} 0770
MAKE_DIRS_PERMS+=	${VARBASE}/run/atheme \
			${ATHEME_USER} ${ATHEME_GROUP} 0770

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/dbverify \
	    ${DESTDIR}${PREFIX}/bin/atheme-dbverify
	${MV} ${DESTDIR}${PREFIX}/bin/ecdsakeygen \
	    ${DESTDIR}${PREFIX}/bin/atheme-ecdsakeygen
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/atheme.conf.example \
	    ${DESTDIR}${EGDIR}/atheme.conf.example
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/atheme.conf.operserv-example \
	    ${DESTDIR}${EGDIR}/atheme.conf.operserv-example
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/atheme.conf.userserv-example \
	    ${DESTDIR}${EGDIR}/atheme.conf.userserv-example
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/atheme.cron.example \
	    ${DESTDIR}${EGDIR}/atheme.cron.example
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/atheme.motd.example \
	    ${DESTDIR}${EGDIR}/atheme.motd.example
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/atheme.motd \
	    ${DESTDIR}${EGDIR}/atheme.motd
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/atheme/
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/qrencode/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
