# $NetBSD: Makefile,v 1.2 2022/11/15 15:08:22 fcambus Exp $

DISTNAME=	ssh-audit-2.5.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=jtesta/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jtesta/ssh-audit/
COMMENT=	Tool for SSH server & client configuration auditing
LICENSE=	mit

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${RUN}${INSTALL_MAN} ${WRKSRC}/ssh-audit.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
