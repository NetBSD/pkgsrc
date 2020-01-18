# $NetBSD: Makefile,v 1.17 2020/01/18 23:35:17 rillig Exp $
#

DISTNAME=	ipa-2.1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipa-system/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	https://ipa-system.sourceforge.net/
COMMENT=	Pluggable accounting system
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=	ipa

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
RCD_SCRIPT_SRC.ipa=	${FILESDIR}/ipa.sh
.else
RCD_SCRIPT_SRC.ipa=	${WRKSRC}/etc/ipa.sh.sample
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-mandir-ru=ru

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
