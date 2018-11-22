# $NetBSD: Makefile,v 1.1 2018/11/22 13:08:28 ryoon Exp $

DISTNAME=	acme.sh-2.7.9
PKGNAME=	${DISTNAME:S/acme.sh/acmesh/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Neilpang/}
GITHUB_PROJECT=	acme.sh
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/Neilpang/acme.sh/
COMMENT=	Let's Encrypt ACME client in shell script
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	socat-[0-9]*:../../net/socat
DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts
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
