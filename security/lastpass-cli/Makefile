# $NetBSD: Makefile,v 1.6 2018/08/16 18:55:10 adam Exp $

DISTNAME=	lastpass-cli-1.3.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=lastpass/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lastpass/lastpass-cli/
COMMENT=	Command line interface to LastPass.com
LICENSE=	gnu-gpl-v2

DEPENDS+=	asciidoc>=0:../../textproc/asciidoc

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	pkg-config

INSTALL_TARGET=	install install-doc

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
