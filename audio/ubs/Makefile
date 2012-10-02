# $NetBSD: Makefile,v 1.17 2012/10/02 23:48:12 asau Exp $
#

DISTNAME=		ubs-0.17
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
# author's new home may be at http://www.teragon.org
# HOMEPAGE=		http://aboleo.net/software/ubs/
COMMENT=		Uninterrupted Broadcasting System

GNU_CONFIGURE=		yes

RCD_SCRIPTS=		ubs
PKG_SYSCONFSUBDIR=	ubs
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CFLAGS.SunOS+=		-std=c99 -D_XOPEN_SOURCE=600

.include "../../mk/bsd.prefs.mk"

UBS_BASEDIR?=		/var/spool/ubs
UBS_USER?=		ubs
UBS_GROUP?=		ubs
PKG_USERS_VARS+=	UBS_USER
PKG_GROUPS_VARS+=	UBS_GROUP
BUILD_DEFS+=		UBS_BASEDIR

PKG_GROUPS=		${UBS_GROUP}
PKG_USERS=		${UBS_USER}:${UBS_GROUP}
FILES_SUBST+=		PREFIX=${PREFIX:Q}
FILES_SUBST+=		UBS_USER=${UBS_USER:Q}
FILES_SUBST+=		UBS_GROUP=${UBS_GROUP:Q}

OWN_DIRS_PERMS=		${UBS_BASEDIR} ${UBS_USER} ${UBS_GROUP} 0750
OWN_DIRS_PERMS+=	${UBS_BASEDIR}/var ${UBS_USER} ${UBS_GROUP} 0750
OWN_DIRS_PERMS+=	${UBS_BASEDIR}/log ${UBS_USER} ${UBS_GROUP} 0750

EGDIR=			${PREFIX}/share/examples/ubs
CONF_FILES=		${EGDIR}/help.conf ${PKG_SYSCONFDIR}/help.conf
CONF_FILES+=		${EGDIR}/ubs.conf.default ${PKG_SYSCONFDIR}/ubs.conf

SUBST_CLASSES+=		ubsconf
SUBST_STAGE.ubsconf=	pre-configure
SUBST_MESSAGE.ubsconf=	Fixing path to ubs.conf.
SUBST_FILES.ubsconf=	include/defaults.h
SUBST_SED.ubsconf=	-e 's,"etc/ubs.conf","${PKG_SYSCONFDIR}/ubs.conf",'

post-extract:
	${MV} ${WRKSRC}/config/ubs.conf.default \
		${WRKSRC}/config/ubs.conf.default.in

pre-configure:
	${SED} -e "s,@UBS_BASEDIR@,${UBS_BASEDIR},g" \
		${WRKSRC}/config/ubs.conf.default.in > \
		${WRKSRC}/config/ubs.conf.default

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
