# $NetBSD: Makefile,v 1.12 2023/02/16 15:01:57 bsiegert Exp $

DISTNAME=	czds-1.2.11
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=lanrat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lanrat/czds
COMMENT=	Client to the CZDS REST API
LICENSE=	gnu-gpl-v3

DOCDIR=		share/doc/czds

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${RUN}${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
