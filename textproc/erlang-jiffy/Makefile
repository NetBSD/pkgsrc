# $NetBSD: Makefile,v 1.1 2015/11/04 13:45:46 fhajny Exp $

DISTNAME=	jiffy-0.14.4
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=davisp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/davisp/jiffy/
COMMENT=	JSON NIFs for Erlang
LICENSE=	mit

BUILD_DEPENDS+=	rebar-[0-9]*:../../devel/rebar

GITHUB_PROJECT=	jiffy
GITHUB_TAG=	${PKGVERSION_NOREV}

NO_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax

SUBST_CLASSES+=		vsn
SUBST_STAGE.vsn=	pre-build
SUBST_MESSAGE.vsn=	Fixing package version
SUBST_FILES.vsn=	src/jiffy.app.src
SUBST_SED.vsn=		-e 's,git,"${PKGVERSION_NOREV}",'

INSTALLATION_DIRS+=	lib/erlang/lib/jiffy

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp ebin priv \
		${DESTDIR}${PREFIX}/lib/erlang/lib/jiffy/

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
