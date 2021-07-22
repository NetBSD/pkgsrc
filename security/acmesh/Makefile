# $NetBSD: Makefile,v 1.11 2021/07/22 19:05:14 tm Exp $

DISTNAME=	acme.sh-2.9.0
PKGREVISION=	1
PKGNAME=	${DISTNAME:S/acme.sh/acmesh/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=acmesh-official/}
GITHUB_PROJECT=	acme.sh
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://acme.sh/
COMMENT=	Let's Encrypt ACME client in shell script
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	socat-[0-9]*:../../net/socat
DEPENDS+=	curl-[0-9]*:../../www/curl

#NO_CONFIGURE=	yes
NO_BUILD=	yes

REPLACE_SH+=	acme.sh

DOCDIR=			share/doc/acmesh
INSTALLATION_DIRS=	sbin \
			${DOCDIR} \
			share/acmesh/deploy \
			share/acmesh/dnsapi \
			share/acmesh/notify

do-configure:
	${MV} ${WRKSRC}/deploy/README.md \
		${WRKSRC}/README-deploy.md
	${MV} ${WRKSRC}/dnsapi/README.md \
		${WRKSRC}/README-dnsapi.md

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/acme.sh \
		${DESTDIR}${PREFIX}/share/acmesh/acme.sh
	${LN} -s ${DESTDIR}${PREFIX}/share/acmesh/acme.sh \
		${DESTDIR}${PREFIX}/sbin/acme.sh

	${INSTALL_DATA} ${WRKSRC}/deploy/* \
		${DESTDIR}${PREFIX}/share/acmesh/deploy
	${INSTALL_DATA} ${WRKSRC}/dnsapi/* \
		${DESTDIR}${PREFIX}/share/acmesh/dnsapi
	${INSTALL_DATA} ${WRKSRC}/notify/* \
		${DESTDIR}${PREFIX}/share/acmesh/notify

	${INSTALL_DATA} ${WRKSRC}/README*.md \
		${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../mk/bsd.pkg.mk"
