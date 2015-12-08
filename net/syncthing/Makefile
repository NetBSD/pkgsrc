# $NetBSD: Makefile,v 1.4 2015/12/08 03:20:55 jnemeth Exp $

DISTNAME=	syncthing-0.12.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://syncthing.net/
COMMENT=	Keeps directories in sync across hosts
LICENSE=	mpl-2.0

BUILD_DEPENDS+=		go-[0-9]*:../../lang/go

USE_LANGUAGES=		# go
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin

MAKE_ENV+=		GOPATH=${WRKDIR}/gopath
INSTALL_UNSTRIPPED=	yes	# XXX for Mac OS?

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-build
SUBST_MESSAGE.version=  Fixing version string
SUBST_FILES.version=	build.go
SUBST_SED.version=	-e 's|runError("git", "describe", "--always", "--dirty")|runError("echo","v${PKGVERSION_NOREV}")|'
SUBST_SED.version+=	-e 's|runError("git", "show", "-s", "--format=%ct")|runError("false")|'

post-extract:
	${MKDIR} ${WRKDIR}/gopath/src/github.com/syncthing
	${LN} -s ${WRKSRC} ${WRKDIR}/gopath/src/github.com/syncthing/syncthing

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/go run build.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/syncthing ${DESTDIR}/${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
