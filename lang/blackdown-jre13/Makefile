# $NetBSD: Makefile,v 1.18 2007/07/31 19:19:57 jlam Exp $
#

BD_BASENAME=	j2re
DISTNAME=	${EXTNAME}-${BLACKDOWN_ARCH}
PKGNAME=	blackdown-jre13-1
PKGREVISION=	2
COMMENT=	Blackdown's Java(tm) Runtime Environment 1.3.1

EMUL_PLATFORMS=	linux-arm

.include "../../lang/blackdown-jre13/Makefile.common"

.if ${BLACKDOWN_ARCH} == "arm"
BLACKDOWN_REL=	rc1
DISTNAME=	${BD_BASENAME}-${RELVERSION}-RC1-linux-arm
EXTRACT_SUFX=	.tar.bz2
.endif

REQD_DIRS=	${JVM_HOME}
REQD_DIRS+=	${JVM_HOME}/lib
REQD_DIRS+=	${JVM_HOME}/lib/${BLACKDOWN_ARCH}
REQD_DIRS+=	${JVM_HOME}/lib/applet
REQD_DIRS+=	${JVM_HOME}/lib/ext
REQD_DIRS+=	${JVM_HOME}/lib/images
REQD_DIRS+=	${JVM_HOME}/lib/images/cursors
REQD_DIRS+=	${JVM_HOME}/lib/security
REQD_DIRS+=	${JVM_HOME}/plugin/${BLACKDOWN_ARCH}
REQD_DIRS+=	${JVM_HOME}/plugin
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties			font.properties.ja
SFILES+=	font.properties.zh		jvm.cfg
SFILES+=	images/cursors/cursors.properties	psfont.properties.ja
SFILES+=	psfontj2d.properties		security/java.security
CONF_FILES=	# empty
.for file in ${SFILES}
CONF_FILES+=	${JVM_HOME}/lib/${file}.default ${JVM_HOME}/lib/${file}
.endfor

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

.include "../../mk/bsd.pkg.mk"
