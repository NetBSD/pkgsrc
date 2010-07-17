# $NetBSD: Makefile,v 1.1.1.1 2010/07/17 08:34:39 obache Exp $
#

DISTNAME=	SKK-JISYO.L.${SKKJISYO_VERS}
PKGNAME=	skk-jisyo-${SKKJISYO_VERS}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	${MASTER_SITE_FREEBSD_LOCAL:=matusita/skk-jisyo/}
EXTRACT_SUFX=	.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://openlab.ring.gr.jp/skk/wiki/wiki.cgi?page=SKK%BC%AD%BD%F1
COMMENT=	Dictionary collection for SKK

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	skkserv<3.9.4nb7

NO_BUILD=	yes

SKKJISYO_VERS=	200708

INSTALLATION_DIRS+=	${PREFIX}/share/skk

do-install:
	${INSTALL_DATA} ${WRKDIR}/SKK-JISYO.L.${SKKJISYO_VERS} \
		${DESTDIR}${PREFIX}/share/skk/SKK-JISYO.L

.include "../../mk/bsd.pkg.mk"
