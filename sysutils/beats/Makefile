# $NetBSD: Makefile,v 1.9 2017/04/28 08:49:32 fhajny Exp $
#

DISTNAME=		beats-5.3.2
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=elastic/}
GITHUB_PROJECT=		beats
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		filip@joyent.com
HOMEPAGE=		https://www.elastic.co/products/beats
COMMENT=		Data Shippers for Elasticsearch
LICENSE=		apache-2.0

.include "../../lang/go/version.mk"
BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go

EXTRACT_USING=		bsdtar
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/src/github.com/elastic/beats

# Components to build/install
BEATS=			filebeat heartbeat metricbeat packetbeat

.for beat in ${BEATS}
CONF_FILES+=		share/examples/beats/${beat}.yml			\
				${PKG_SYSCONFDIR}/${beat}.yml
CONF_FILES+=		share/examples/beats/${beat}.template.json		\
				${PKG_SYSCONFDIR}/${beat}.template.json
CONF_FILES+=		share/examples/beats/${beat}.template-es2x.json		\
				${PKG_SYSCONFDIR}/${beat}.template-es2x.json
.endfor

BEATS_DIR?=		${VARBASE}/db/beats
BEATS_LOGDIR?=		${VARBASE}/log/beats

FILES_SUBST+=		BEATS_DIR=${BEATS_DIR}
FILES_SUBST+=		BEATS_LOGDIR=${BEATS_LOGDIR}

PKG_SYSCONFSUBDIR=	beats

SMF_INSTANCES+=		${BEATS}

OWN_DIRS+=		${BEATS_DIR} ${BEATS_LOGDIR}

MAKE_ENV+=		GOPATH=${WRKDIR}:${PREFIX}/gopkg
BUILD_DIRS=		${BEATS}
BUILD_TARGET=		#

INSTALLATION_DIRS+=	bin share/examples/beats

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/${DISTNAME}/* ${WRKSRC}

do-install:
.for beat in ${BEATS}
	${INSTALL_PROGRAM} ${WRKSRC}/${beat}/${beat} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${beat}/${beat}.full.yml			\
		${DESTDIR}${PREFIX}/share/examples/beats
	${INSTALL_DATA} ${WRKSRC}/${beat}/${beat}.template-es2x.json		\
		${DESTDIR}${PREFIX}/share/examples/beats
	${INSTALL_DATA} ${WRKSRC}/${beat}/${beat}.template.json			\
		${DESTDIR}${PREFIX}/share/examples/beats
	${INSTALL_DATA} ${WRKSRC}/${beat}/${beat}.yml				\
		${DESTDIR}${PREFIX}/share/examples/beats
.endfor

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
