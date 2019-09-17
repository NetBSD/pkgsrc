# $NetBSD: Makefile,v 1.17 2019/09/17 08:21:01 adam Exp $

DISTNAME=	mongo-tools-3.4.23
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mongodb/}
GITHUB_TAG=	r${PKGVERSION_NOREV}

MAINTAINER=	fhajny@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-tools
COMMENT=	MongoDB CLI tools
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${GO_PACKAGE_DEP}

EXTRACT_USING=	bsdtar
USE_TOOLS+=	pkg-config

.include "options.mk"

# TODO: mongoreplay
MONGO_TOOLS=	bsondump mongodump mongoexport mongofiles mongoimport \
		mongooplog mongorestore mongostat mongotop

# go uses volatile /tmp dirs that contain required includes files too
BUILDLINK_PASSTHRU_DIRS+=	/tmp

INSTALLATION_DIRS+=		bin

post-extract:
	${MKDIR} -p ${WRKSRC}/vendor/github.com/mongodb/mongo-tools
.for tool in common ${MONGO_TOOLS}
	${LN} -s ${WRKSRC}/${tool} ${WRKSRC}/vendor/github.com/mongodb/mongo-tools/${tool}
.endfor
	${MKDIR} -p ${WRKSRC}/vendor/src
.for site in github.com golang.org gopkg.in
	${LN} -s ${WRKSRC}/vendor/${site} ${WRKSRC}/vendor/src/${site}
.endfor

do-build:
.for tool in ${MONGO_TOOLS}
	cd ${WRKSRC} && \
	  ${SETENV} GOPATH=${WRKSRC}:${WRKSRC}/vendor:${PREFIX}/gopkg \
	  ${GO} build -tags "${MONGO_TAGS}" -o bin/${tool} ${tool}/main/${tool}.go
.endfor

do-install:
.for tool in ${MONGO_TOOLS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${tool} ${DESTDIR}${PREFIX}/bin/${tool}
.endfor

.include "../../lang/go/version.mk"
.include "../../devel/go-sys/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
