# $NetBSD: Makefile,v 1.15 2004/04/25 08:40:46 snj Exp $
#

DISTNAME=	ipa-1.3.6
CATEGORIES=	net sysutils
MASTER_SITES=	http://ipa-system.sourceforge.net/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/ipa/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/network-monitoring/ipa/ \
		http://ipa.it-ss.be/

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/
COMMENT=	IP accounting software

ONLY_FOR_PLATFORM=	*BSD-*-*

RESTRICTED=		"Needs to be built uniquely for each host"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_PACKAGE=		${RESTRICTED}

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
ALL_TARGET=		# empty

CFLAGS+=		-DCFGFILE=\\\"${PKG_SYSCONFDIR}/ipa.conf\\\"

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

post-patch:
	@cd ${WRKSRC}/man &&					\
	for f in ipa.5 ipa.8 ipa.conf.5 ipastat.8; do		\
		${MV} $${f} $${f}.orig;				\
		${SED} ${FILES_SUBST_SED} $${f}.orig > $${f};	\
	done

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ipa

.include "../../mk/bsd.pkg.mk"
