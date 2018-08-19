# $NetBSD: Makefile,v 1.16 2018/08/19 18:08:05 leot Exp $

DISTNAME=	jq-1.5
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=stedolan/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/stedolan/jq/
COMMENT=	Command-line JSON processor
LICENSE=	mit

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf autoconf automake bison flex gmake
GNU_CONFIGURE=	yes

SUBST_CLASSES+=		tag
SUBST_STAGE.tag=	pre-configure
SUBST_MESSAGE.tag=	Avoid to run `git describe' to fetch the tag
SUBST_FILES.tag=	configure.ac scripts/version
SUBST_SED.tag+=		-e 's/git describe .*|/echo "jq-1.5-1-g940132e-dirty" |/'

TEST_TARGET=	check

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
