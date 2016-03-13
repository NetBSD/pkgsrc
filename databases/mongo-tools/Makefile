# $NetBSD: Makefile,v 1.5 2016/03/13 21:05:34 fhajny Exp $

DISTNAME=	mongo-tools-3.2.4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mongodb/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/mongodb/mongo-tools/
COMMENT=	MongoDB CLI tools
LICENSE=	apache-2.0

GITHUB_TAG=	r${PKGVERSION_NOREV}

BUILD_DEPENDS+=	go-${GO_VERSION}*:../../lang/go

EXTRACT_USING=	bsdtar
USE_TOOLS+=	pkg-config

.include "options.mk"

MONGO_TOOLS=	bsondump mongostat mongofiles mongoexport mongoimport \
		mongorestore mongodump mongotop mongooplog

# go uses volatile /tmp dirs that contain required includes files too
BUILDLINK_PASSTHRU_DIRS+=	/tmp

INSTALLATION_DIRS+=		bin

post-extract:
	${MKDIR} -p ${WRKSRC}/vendor/src/github.com/mongodb/mongo-tools
.for tool in common ${MONGO_TOOLS}
	${LN} -s ${WRKSRC}/${tool} ${WRKSRC}/vendor/src/github.com/mongodb/mongo-tools/${tool}
.endfor

do-build:
.for tool in ${MONGO_TOOLS}
	cd ${WRKSRC} && \
	  ${SETENV} GOPATH=${WRKSRC}:${WRKSRC}/vendor:${PREFIX}/gopkg \
	  go build -tags "${MONGO_TAGS}" -o bin/${tool} ${tool}/main/${tool}.go
.endfor

do-install:
.for tool in ${MONGO_TOOLS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${tool} ${DESTDIR}${PREFIX}/bin/${tool}
.endfor

.include "../../lang/go/version.mk"
.include "../../mk/bsd.pkg.mk"
