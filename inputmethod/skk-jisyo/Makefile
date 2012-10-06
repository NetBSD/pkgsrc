# $NetBSD: Makefile,v 1.3 2012/10/06 14:25:18 asau Exp $
#

DISTNAME=	SKK-JISYO.L.${SKKJISYO_VERS}
PKGNAME=	skk-jisyo-${SKKJISYO_VERS}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	${MASTER_SITE_FREEBSD_LOCAL:=matusita/skk-jisyo/}
EXTRACT_SUFX=	.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/wiki/wiki.cgi?page=SKK%BC%AD%BD%F1
COMMENT=	Dictionary collection for SKK

CONFLICTS=	skkserv<3.9.4nb7

NO_BUILD=	yes

SKKJISYO_VERS=	200708

INSTALLATION_DIRS+=	${PREFIX}/share/skk

do-install:
	${INSTALL_DATA} ${WRKDIR}/SKK-JISYO.L.${SKKJISYO_VERS} \
		${DESTDIR}${PREFIX}/share/skk/SKK-JISYO.L

.include "../../mk/bsd.pkg.mk"
