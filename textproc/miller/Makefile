# $NetBSD: Makefile,v 1.5 2015/12/29 23:43:18 wiz Exp $

DISTNAME=	miller-3.2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnkerl/}
GITHUB_PROJECT=	miller
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/johnkerl/miller/
COMMENT=	Command-line CSV processor
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf autoconf automake
BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
