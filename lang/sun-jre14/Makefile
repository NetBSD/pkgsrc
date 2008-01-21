# $NetBSD: Makefile,v 1.46 2008/01/21 01:39:01 tnn Exp $

# Note: Regen distinfo with PKG_DEFAULT_OPTIONS+=sun-jre-jce

DISTNAME=	j2re-1_4_2_16-linux-${DIST_ARCH}
PKGNAME=	sun-jre14-2.16
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) 2 Runtime Environment 1.4.2

SHORT=		JRE

WRKSRC=		${WRKDIR}/j2re1.4.2_16
JAVA_WRAPPERS=	java keytool orbd policytool rmid rmiregistry \
		servertool tnameserv

LICENSE=	sun-jre14-license

.include "../../lang/sun-jre14/Makefile.common"

REQD_DIRS=	${JAVA_HOME}
REQD_DIRS+=	${JAVA_HOME}/lib
REQD_DIRS+=	${JAVA_HOME}/lib/applet
REQD_DIRS+=	${JAVA_HOME}/lib/images
REQD_DIRS+=	${JAVA_HOME}/lib/images/cursors
REQD_DIRS+=	${JAVA_HOME}/lib/security
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties.Redhat6.1	font.properties
SFILES+=	font.properties.ja.Redhat6.1	font.properties.ja.Redhat6.2
SFILES+=	font.properties.ja.Turbo	font.properties.ja.Turbo6.0
SFILES+=	font.properties.ja		font.properties.zh.Turbo
SFILES+=	images/cursors/cursors.properties	i386/jvm.cfg
SFILES+=	logging.properties		psfont.properties.ja
SFILES+=	psfontj2d.properties		security/java.security
CONF_FILES=	# empty
.for FILE in ${SFILES}
CONF_FILES+=	${JAVA_HOME}/lib/${FILE}.default ${JAVA_HOME}/lib/${FILE}
.endfor

PKG_OPTIONS_VAR=	PKG_OPTIONS.sun-jre14
PKG_SUPPORTED_OPTIONS=	sun-jre-jce

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msun-jre-jce)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} jce_policy-1_4_2.zip
PLIST_SUBST+=	SUN_JRE14_USE_JCE=""

END_MESSAGE=								\
	""								\
	"The file jce_policy-1_4_2.zip must be fetched into:"		\
	"    ${DISTDIR}/jce_policy-1_4_2.zip"				\
	""								\
	"Under 'Other Downloads' / 'Java Cryptography Extension'"	\
	"click 'Download' and choose the .zip file."
.else
PLIST_SUBST+=	SUN_JRE14_USE_JCE="@comment "
.endif

# Some of the binaries require libX11, so ensure that requirement is
# satisfied when the package is installed on the native OS.
#
.if defined(EMUL_IS_NATIVE)
.  if ${X11_TYPE} == "native"
.    if ${EMUL_ARCH} == "x86_64"
LIBX11=		${X11PREFIX}/lib64/libX11.so.6
.    else
LIBX11=		${X11PREFIX}/lib/libX11.so.6
.    endif
.    if !exists(${LIBX11})
PKG_FAIL_REASON+=	"${LIBX11} does not exist.  Please install the" \
			"X11 library packages for your system."
.    endif
.  else
.    include "../../x11/libX11/buildlink3.mk"
LIBX11=		${X11PREFIX}/lib/libX11.so.6
.  endif

PLIST_SUBST+=		LIBX11=

.PHONY: create-library-symlinks
post-install: create-library-symlinks
create-library-symlinks:
	${RUN}${LN} -fs ${LIBX11} ${JAVA_HOME}/lib/${EMUL_ARCH}
.else
PLIST_SUBST+=		LIBX11="@comment "
.endif

post-extract:
	cd ${WRKSRC} && ${CHMOD} -R go-w .

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

pre-install:
.if !empty(PKG_OPTIONS:Msun-jre-jce)
	cd ${WRKDIR}/jce ; ${PAX} -rw -pe -v . ${WRKSRC}/lib/security
.endif

.include "../../mk/bsd.pkg.mk"
