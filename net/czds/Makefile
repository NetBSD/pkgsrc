# $NetBSD: Makefile,v 1.22 2023/10/29 14:48:14 bsiegert Exp $

DISTNAME=	czds-1.2.14
PKGREVISION=	3
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
