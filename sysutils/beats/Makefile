# $NetBSD: Makefile,v 1.45 2019/10/18 14:58:56 bsiegert Exp $

DISTNAME=		beats-6.6.2
PKGREVISION=		6
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=elastic/}
GITHUB_PROJECT=		beats
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		fhajny@NetBSD.org
HOMEPAGE=		https://www.elastic.co/products/beats
COMMENT=		Data Shippers for Elasticsearch
LICENSE=		apache-2.0

EXTRACT_USING=		bsdtar
USE_TOOLS+=		gmake

GO_DIST_BASE=		${PKGBASE}-${GITHUB_TAG:S/v//}
GO_SRCPATH=		github.com/elastic/beats

TOOLS_CREATE+=		go
TOOLS_PATH.go=		${GO}

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		audit

# Components to build/install
BEATS=			filebeat heartbeat metricbeat packetbeat

# No SunOS compatible event reading supported
.if ${OPSYS} != "SunOS"
BEATS+=			auditbeat
PLIST.audit=		yes
.endif

.for beat in ${BEATS}
CHECK_RELRO_SKIP+=	bin/${beat}
CONF_FILES+=		share/examples/beats/${beat}.yml			\
				${PKG_SYSCONFDIR}/${beat}.yml
.endfor

BEATS_DIR?=		${VARBASE}/db/beats
BEATS_LOGDIR?=		${VARBASE}/log/beats

FILES_SUBST+=		BEATS_DIR=${BEATS_DIR}
FILES_SUBST+=		BEATS_LOGDIR=${BEATS_LOGDIR}

PKG_SYSCONFSUBDIR=	beats

SMF_INSTANCES+=		${BEATS}

OWN_DIRS+=		${BEATS_DIR} ${BEATS_LOGDIR}

MAKE_ENV+=		GOPATH=${WRKDIR}:${PREFIX}/gopkg
MAKE_ENV+=		CGO_LDFLAGS="-L${BUILDLINK_PREFIX.libpcap}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libpcap}/lib"

# The build system defaults to -i which modifies system files!
MAKE_ENV+=		GOBUILD_FLAGS=

BUILD_TARGET=		#

INSTALLATION_DIRS+=	bin share/examples/beats

do-build:
.for beat in ${BEATS}
	cd ${WRKSRC}/${beat} && ${BUILD_MAKE_CMD}
.endfor

do-install:
.for beat in ${BEATS}
	${INSTALL_PROGRAM} ${WRKSRC}/${beat}/${beat} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${beat}/${beat}.reference.yml			\
		${DESTDIR}${PREFIX}/share/examples/beats
	${INSTALL_DATA} ${WRKSRC}/${beat}/${beat}.yml				\
		${DESTDIR}${PREFIX}/share/examples/beats
.endfor

.include "../../lang/go/go-package.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
