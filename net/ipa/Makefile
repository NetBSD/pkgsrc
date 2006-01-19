# $NetBSD: Makefile,v 1.23 2006/01/19 01:51:48 joerg Exp $
#

DISTNAME=	ipa-1.3.6
PKGREVISION=	1
CATEGORIES=	net sysutils
MASTER_SITES=	http://ipa-system.sourceforge.net/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/ipa/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/network-monitoring/ipa/ \
		http://ipa.it-ss.be/

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/
COMMENT=	IP accounting software

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-1*-* OpenBSD-*-* DragonFly-*-*

RESTRICTED=		"Needs to be built uniquely for each host"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_PACKAGE=		${RESTRICTED}

BUILD_TARGET=		# empty

CFLAGS+=		-DCFGFILE="\"${PKG_SYSCONFDIR}/ipa.conf\""

CONF_FILES_PERMS=	${PREFIX}/share/examples/ipa/ipa.conf.default	\
			${PKG_SYSCONFDIR}/ipa.conf			\
			${ROOT_USER} ${ROOT_GROUP} 0400
OWN_DIRS_PERMS=		/var/ipa ${ROOT_USER} ${ROOT_GROUP} 0555

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=		ipa

.if ${OPSYS} == "NetBSD"
RCD_SCRIPT_SRC.ipa=	${FILESDIR}/ipa.sh
.else
RCD_SCRIPT_SRC.ipa=	${FILESDIR}/ipa.generic
.endif

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	man/ipa.5 man/ipa.8 man/ipa.conf.5 man/ipastat.8
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ipa

.include "../../mk/bsd.pkg.mk"
