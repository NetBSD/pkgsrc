# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:10 tv Exp $
#

DISTNAME=		ubs-0.17
PKGREVISION=	1
CATEGORIES=		audio
MASTER_SITES=		http://aboleo.net/software/ubs/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://aboleo.net/software/ubs/
COMMENT=		Uninterrupted Broadcasting System

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes

RCD_SCRIPTS=		ubs
PKG_SYSCONFSUBDIR=	ubs
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		UBS_BASEDIR UBS_USER UBS_GROUP

UBS_BASEDIR?=		/var/spool/ubs
UBS_USER?=		ubs
UBS_GROUP?=		ubs

PKG_GROUPS=             ${UBS_GROUP}
PKG_USERS=              ${UBS_USER}:${UBS_GROUP}
FILES_SUBST+=		PREFIX="${PREFIX}"
FILES_SUBST+=		UBS_USER="${UBS_USER}"
FILES_SUBST+=		UBS_GROUP="${UBS_GROUP}"

OWN_DIRS_PERMS=		${UBS_BASEDIR} ${UBS_USER} ${UBS_GROUP} 0750
OWN_DIRS_PERMS+=	${UBS_BASEDIR}/var ${UBS_USER} ${UBS_GROUP} 0750
OWN_DIRS_PERMS+=	${UBS_BASEDIR}/log ${UBS_USER} ${UBS_GROUP} 0750

EGDIR=			${PREFIX}/share/examples/ubs
CONF_FILES=		${EGDIR}/help.conf ${PKG_SYSCONFDIR}/help.conf
CONF_FILES+=		${EGDIR}/ubs.conf.default ${PKG_SYSCONFDIR}/ubs.conf

post-extract:
	@${MV} ${WRKSRC}/config/ubs.conf.default \
		${WRKSRC}/config/ubs.conf.default.in

pre-configure:
	@${SED} -e "s,@UBS_BASEDIR@,${UBS_BASEDIR},g" \
		${WRKSRC}/config/ubs.conf.default.in > \
		${WRKSRC}/config/ubs.conf.default

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
