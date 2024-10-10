# $NetBSD: Makefile,v 1.19 2024/10/10 18:03:56 nia Exp $
#

DISTNAME=	ipa-2.1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipa-system/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/
COMMENT=	Pluggable accounting system
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

CFLAGS.SunOS+=	-D_POSIX_C_SOURCE=200809L -D__EXTENSIONS__

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
