# $NetBSD: Makefile,v 1.1 2019/01/18 04:44:28 tpaul Exp $

DISTNAME=	blackbox-1.20181219
PKGNAME=	scm-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=StackExchange/}
GITHUB_PROJECT=	blackbox
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/StackExchange/blackbox
COMMENT=	Safely store secrets in Git/Mercurial/Subversion
LICENSE=	mit

USE_TOOLS+=	bash:run

DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

REPLACE_BASH+=	bin/*blackbox*

INSTALLATION_DIRS+=	bin
NO_BUILD=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/_stack_lib.sh ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*blackbox* ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
