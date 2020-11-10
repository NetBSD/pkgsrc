# $NetBSD: Makefile,v 1.8 2020/11/10 19:04:45 kim Exp $

DISTNAME=	acme.sh-2.8.7
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

INSTALLATION_DIRS=	sbin

do-configure:
	# empty for REPLACE_SH

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/acme.sh \
		${DESTDIR}${PREFIX}/sbin/acme.sh

.include "../../mk/bsd.pkg.mk"
