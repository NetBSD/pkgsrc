# $NetBSD: Makefile,v 1.14 2011/11/23 07:51:54 obache Exp $
#

DISTNAME=	ipa-2.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipa-system/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/
COMMENT=	Pluggable accounting system
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

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
