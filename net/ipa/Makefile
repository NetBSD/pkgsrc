# $NetBSD: Makefile,v 1.9 2003/03/05 07:11:41 wiz Exp $

DISTNAME=	ipa-1.3.1
CATEGORIES=	net sysutils
MASTER_SITES=	http://ipa-system.sourceforge.net/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/ipa/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/network-monitoring/ipa/ \
		http://ipa.it-ss.be/

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/
COMMENT=	IP accounting software

RESTRICTED=		"Needs to be built uniquely for each host"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_PACKAGE=		${RESTRICTED}

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
ALL_TARGET=		# empty

CFLAGS+=		-DCFGFILE=\\\"${PKG_SYSCONFDIR}/ipa.conf\\\"

CONF_FILES_PERMS=	${PREFIX}/share/examples/ipa/ipa.conf.default	\
			${PKG_SYSCONFDIR}/ipa.conf			\
			${ROOT_USER} ${ROOT_GROUP} 0400
RCD_SCRIPTS=		ipa

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/ipa

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
