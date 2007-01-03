# $NetBSD: Makefile,v 1.2 2007/01/03 12:31:00 obache Exp $
#

DISTNAME=	ipa-2.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://ipa-system.sourceforge.net/ \
		http://www.mirrors.wiretapped.net/security/network-monitoring/ipa/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/network-monitoring/ipa/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/
COMMENT=	Pluggable accounting system

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=	ipa

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
RCD_SCRIPT_SRC.ipa=	${FILESDIR}/ipa.sh
.else
RCD_SCRIPT_SRC.ipa=	${WRKSRC}/etc/ipa.sh.sample
.endif

CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR:Q}

.include "options.mk"

do-install:
	cd ${WRKSRC}/src && ${MAKE} install
	cd ${WRKSRC}/man && ${MAKE} install-am

.include "../../mk/bsd.pkg.mk"
