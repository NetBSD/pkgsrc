# $NetBSD: Makefile,v 1.8 2009/07/10 08:20:03 obache Exp $
#

DISTNAME=	ipa-2.0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://ipa-system.sourceforge.net/ 
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	simon@comsys.ntu-kpi.kiev.ua
HOMEPAGE=	http://ipa-system.sourceforge.net/
COMMENT=	Pluggable accounting system

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
