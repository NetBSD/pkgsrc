# $NetBSD: Makefile,v 1.40 2024/06/01 14:02:49 bsiegert Exp $

DISTNAME=	mongo-tools-100.7.5
PKGREVISION=	10
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mongodb/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-tools
COMMENT=	MongoDB CLI tools
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${GO_PACKAGE_DEP}

EXTRACT_USING=	bsdtar
USE_TOOLS+=	pkg-config

# Include this first so the proper flags get set for a go program before 
# anything from mk/ checking the details of the toolchain is included.
.include "../../lang/go/go-vars.mk"

CHECK_PORTABILITY_SKIP=	vendor/go.mongodb.org/mongo-driver/etc/add-license.sh

.include "options.mk"

MONGO_TOOLS=	bsondump mongodump mongoexport mongofiles mongoimport \
		mongorestore mongostat mongotop

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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

do-install:
.for tool in ${MONGO_TOOLS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${tool} ${DESTDIR}${PREFIX}/bin/${tool}
.endfor

.include "../../lang/go/version.mk"
.include "../../devel/go-sys/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
