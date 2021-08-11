# $NetBSD: Makefile,v 1.23 2021/08/11 07:23:18 adam Exp $

DISTNAME=	mongo-tools-4.2.15
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mongodb/}
GITHUB_TAG=	r${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-tools
COMMENT=	MongoDB CLI tools
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${GO_PACKAGE_DEP}

EXTRACT_USING=	bsdtar
USE_TOOLS+=	pkg-config

CHECK_PORTABILITY_SKIP=	vendor/go.mongodb.org/mongo-driver/etc/add-license.sh

.include "options.mk"

MONGO_TOOLS=	bsondump mongodump mongoexport mongofiles mongoimport \
		mongoreplay mongorestore mongostat mongotop

# go uses volatile /tmp dirs that contain required includes files too
BUILDLINK_PASSTHRU_DIRS+=	/tmp

INSTALLATION_DIRS+=		bin

post-extract:
	${MKDIR} -p ${WRKSRC}/vendor/github.com/mongodb/mongo-tools
.for tool in common legacy ${MONGO_TOOLS}
	${LN} -s ${WRKSRC}/${tool} ${WRKSRC}/vendor/github.com/mongodb/mongo-tools/${tool}
.endfor
	${MKDIR} -p ${WRKSRC}/vendor/src
.for site in github.com golang.org go.mongodb.org gopkg.in
	${LN} -s ${WRKSRC}/vendor/${site} ${WRKSRC}/vendor/src/${site}
.endfor

MAKE_ENV+=	GO111MODULE=off
MAKE_ENV+=	GOPATH=${WRKSRC}:${WRKSRC}/vendor:${PREFIX}/gopkg

do-build:
.for tool in ${MONGO_TOOLS}
	cd ${WRKSRC} && \
	  ${PKGSRC_SETENV} ${MAKE_ENV} \
	  ${GO} build -tags "${MONGO_TAGS}" -o bin/${tool} ${tool}/main/${tool}.go
.endfor

do-install:
.for tool in ${MONGO_TOOLS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${tool} ${DESTDIR}${PREFIX}/bin/${tool}
.endfor

.include "../../lang/go/version.mk"
.include "../../devel/go-sys/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
