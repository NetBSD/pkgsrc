# $NetBSD: Makefile,v 1.7 2024/05/11 18:43:26 wiz Exp $

DISTNAME=	0.17.0
PKGNAME=	aerc-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	https://git.sr.ht/~rjarry/aerc/archive/
DIST_SUBDIR=	aerc

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~rjarry/aerc/
COMMENT=	Terminal email client written in Go
LICENSE=	mit

TOOL_DEPENDS+=	scdoc-[0-9]*:../../textproc/scdoc

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake
USE_LANGUAGES=	c

INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX:Q}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}
MKPIE_SUPPORTED=	no
RELRO_SUPPORTED=	no

SUBST_CLASSES+=		prefix
SUBST_SED.prefix+=	-e "s,/usr/local,${PREFIX},"
SUBST_SED.prefix+=	-e "s,/usr/share,${PREFIX}/share,"
SUBST_FILES.prefix+=	config/aerc.conf
SUBST_FILES.prefix+=	config/config.go
SUBST_FILES.prefix+=	doc/aerc-config.5.scd
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Adapt hardcoded prefix for pkgsrc.

REPLACE_PYTHON+=	contrib/carddav-query
REPLACE_PYTHON+=	filters/show-ics-details.py

GO_BUILD_PATTERN=	.

GO_LDFLAGS+=	-X main.Version=${PKGVERSION_NOREV}
GO_LDFLAGS+=	-X main.Date=2024-04-05
GO_LDFLAGS+=	-X git.sr.ht/~rjarry/aerc/config.shareDir=${PREFIX}/share/aerc
GO_LDFLAGS+=	-X git.sr.ht/~rjarry/aerc/config.libexecDir=${PREFIX}/libexec/aerc
#GO_LDFLAGS+=	-L ${BUILDLINK_PREFIX.notmuch}/lib
#GO_LDFLAGS+=	-r ${BUILDLINK_PREFIX.notmuch}/lib

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV}	\
	    GOPATH=${WRKDIR}/.gopath ${GO} ${GOFLAGS} build -ldflags=${GO_LDFLAGS:Q} -o aerc
#	    GOPATH=${WRKDIR}/.gopath ${GO} ${GOFLAGS} build -tags=notmuch -ldflags=${GO_LDFLAGS:Q} -o aerc

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_MAKE_FLAGS} install

.include "go-modules.mk"

.include "../../lang/python/application.mk"
.include "../../lang/go/go-module.mk"
#.include "../../mail/notmuch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
