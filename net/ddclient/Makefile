# $NetBSD: Makefile,v 1.57 2025/12/12 18:22:51 vins Exp $

DISTNAME=	ddclient-4.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ddclient/}
GITHUB_TAG=	v${DISTNAME:S/ddclient-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ddclient.net/
COMMENT=	Client to update dynamic DNS entries
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		perl:run
USE_LANGUAGES=		# empty
USE_TOOLS+=		autoreconf autoconf automake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE} --sysconfdir=${PKG_SYSCONFDIR}

BUILD_DEFS+=		VARBASE
DOCDIR=			${PREFIX}/share/doc/ddclient
EGDIR=			${PREFIX}/share/examples/ddclient
RCD_SCRIPTS=		ddclient

CONF_FILES+=		${EGDIR}/ddclient.conf \
			${PKG_SYSCONFDIR}/ddclient.conf

DEPENDS+=		curl-[0-9]*:../../www/curl
DEPENDS+=		p5-JSON-Any>=0.0:../../converters/p5-JSON-Any

REPLACE_INTERPRETER+=	sh
REPLACE.sh.old=		.*/bin/bash
REPLACE.sh.new=		/bin/sh
REPLACE_FILES.sh=	sample-ddclient-wrapper.sh
REPLACE_FILES.sh+=	sample-get-ip-from-fritzbox

SUBST_CLASSES+=		curlpath
SUBST_STAGE.curlpath=	pre-configure
SUBST_FILES.curlpath=	sample-get-ip-from-fritzbox
SUBST_SED.curlpath=	-e "s,^curl ,${PREFIX}/bin/curl ,"

BUILDLINK_TRANSFORM+=	rm:-Werror

INSTALLATION_DIRS=	sbin share/doc/ddclient share/examples/ddclient

pre-configure:
	${RUN} set -e; cd ${WRKSRC} && autoreconf -fiv

post-install:
	${MV} -f ${DESTDIR}${PKG_SYSCONFDIR}/ddclient/ddclient.conf \
		${DESTDIR}${EGDIR}/ddclient.conf
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.cisco ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-d* ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-e* ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sample-get-ip-from-fritzbox \
                ${DESTDIR}${PREFIX}/bin/get-ip-from-fritzbox

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
