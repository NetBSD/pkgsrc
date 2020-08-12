# $NetBSD: Makefile,v 1.5 2020/08/12 19:14:22 ryoon Exp $
#

DISTNAME=	SKK-JISYO.L.${SKKJISYO_VERS}
PKGNAME=	skk-jisyo-${SKKJISYO_VERS}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://openlab.ring.gr.jp/skk/wiki/wiki.cgi?page=SKK%BC%AD%BD%F1
COMMENT=	Dictionary collection for SKK
LICENSE=	gnu-gpl-v2

CONFLICTS=	skkserv<3.9.4nb7

NO_BUILD=	yes

SKKJISYO_VERS=	20200809

INSTALLATION_DIRS+=	${PREFIX}/share/skk

do-install:
	${INSTALL_DATA} ${WRKDIR}/SKK-JISYO.L.${SKKJISYO_VERS} \
		${DESTDIR}${PREFIX}/share/skk/SKK-JISYO.L

.include "../../mk/bsd.pkg.mk"
