# $NetBSD: Makefile,v 1.7 2023/03/13 09:32:25 jperkin Exp $

# Note: Regen distinfo with PKG_OPTIONS.oracle-jre8+=oracle-jre-jce
# Note: Update DOWNLOAD_NAME when you update the JRE version
# Note: This needs to be kept in sync with the oracle-jdk8 package
# Note: If you make makesum, make sure that you include both archs in distinfo

DISTNAME=	jre-8u${UPDATE_NUMBER}-${DIST_OS}-${DIST_ARCH}
PKGNAME=	oracle-jre8-8.0.${UPDATE_NUMBER}
MASTER_SITES=	# empty

LICENSE=	oracle-binary-code-license

DOWNLOAD_NAME=	Java Runtime Environment (JRE) 8u${UPDATE_NUMBER}

USE_TOOLS+=	pax

JAVA_WRAPPERS=	java javaws keytool orbd policytool rmid rmiregistry \
		servertool tnameserv
REQD_DIRS=	${JAVA_HOME}
REQD_DIRS+=	${JAVA_HOME}/lib
REQD_DIRS+=	${JAVA_HOME}/lib/applet
REQD_DIRS+=	${JAVA_HOME}/lib/images
REQD_DIRS+=	${JAVA_HOME}/lib/images/cursors
REQD_DIRS+=	${JAVA_HOME}/lib/security
CONF_FILES=	# empty

.include "../../lang/oracle-jre8/Makefile.common"

.if ${OPSYS} == "Darwin"
WRKSRC=		${WRKDIR}/jre1.8.0_${UPDATE_NUMBER}.jre/Contents/Home
.else
WRKSRC=		${WRKDIR}/jre1.8.0_${UPDATE_NUMBER}
.endif

SFILES_MK=	sfiles-${DIST_OS}-${EMUL_ARCH}.mk

.sinclude "${SFILES_MK}"

.for file in ${SFILES}
CONF_FILES+=	${JAVA_HOME}/lib/${file}.default ${JAVA_HOME}/lib/${file}
.endfor

CHECK_FILES_SKIP+=	${JAVA_HOME}/lib/${JAVA_ARCH}/client/classes.jsa

PKG_OPTIONS_VAR=	PKG_OPTIONS.oracle-jre8
PKG_SUPPORTED_OPTIONS=	oracle-jre-jce

.include "../../mk/bsd.options.mk"

PLIST_SRC=	PLIST.${DIST_OS}-${EMUL_ARCH}

PLIST_VARS+=	jce native
.if !empty(PKG_OPTIONS:Moracle-jre-jce)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} jce_policy-8.zip
.endif
.if !empty(PKG_OPTIONS:Moracle-jre-jce)
PLIST.jce=	yes
FETCH_MESSAGE+=	""
FETCH_MESSAGE+=	"As oracle-jre-jce is enabled jce_policy-8.zip from http://www.oracle.com/technetwork/java/javase/downloads/jce8-download-2133166.html is also needed"
.endif

# Simplify distinfo generation
.if make(distinfo) || make (makesum) || make(mdi)
DISTFILES=	jce_policy-8.zip
DISTFILES+=	jre-8u${UPDATE_NUMBER}-linux-i586.tar.gz
DISTFILES+=	jre-8u${UPDATE_NUMBER}-linux-x64.tar.gz
DISTFILES+=	jre-8u${UPDATE_NUMBER}-macosx-x64.tar.gz
DISTFILES+=	jre-8u${UPDATE_NUMBER}-solaris-x64.tar.gz
FETCH_MESSAGE=	"You must fetch the following files to generate distinfo:"
FETCH_MESSAGE+=	""
.  for file in ${DISTFILES}
FETCH_MESSAGE+=	"	${file}"
.  endfor
FETCH_MESSAGE+=	""
FETCH_MESSAGE+=	"from:"
FETCH_MESSAGE+=	"	${DOWNLOAD}"
FETCH_MESSAGE+=	"	or ${ARCHIVE}"
.endif

# Some of the binaries require libX11, so ensure that requirement is
# satisfied when the package is installed on the native OS.
#
.if defined(EMUL_IS_NATIVE) && ${OPSYS} != "SunOS" && ${OPSYS} != "Darwin"
.  if ${X11_TYPE} == "native"
X11_LIBDIR=	${X11BASE}/lib${LIBABISUFFIX}
.    if ${SHLIB_TYPE} == "dylib"
X11_LIB=${X11_LIBDIR}/libX11.dylib
.    else
X11_LIB=${X11_LIBDIR}/libX11.so.6
.    endif
.    if !exists(${X11_LIB})
PKG_FAIL_REASON+=	"${X11_LIB} does not exist.  Please install the" \
			"X11 library packages for your system."
.    endif
.  else
.    include "../../x11/libX11/buildlink3.mk"
.    include "../../x11/libXext/buildlink3.mk"
.    include "../../x11/libXi/buildlink3.mk"
.    include "../../x11/libXt/buildlink3.mk"
.    include "../../x11/libXtst/buildlink3.mk"
X11_LIBDIR=	${X11BASE}/lib
.  endif

.  if ${EMUL_OPSYS} == "linux"
.    include "../../audio/alsa-lib/buildlink3.mk"
ALSA_LIBDIR=	${BUILDLINK_PREFIX.alsa-lib}/${BUILDLINK_LIBDIRS.alsa-lib}

.    include "../../databases/unixodbc/buildlink3.mk"
ODBC_LIBDIR=	${BUILDLINK_PREFIX.unixodbc}/${BUILDLINK_LIBDIRS.unixodbc}
.  endif

ARCH_LIBDIR=	${JAVA_HOME}/lib/${JAVA_ARCH}
.PHONY: create-library-symlinks
post-install: create-library-symlinks
create-library-symlinks:
	${RUN}${LN} -fs ${X11_LIBDIR}/libX11.so.6 ${DESTDIR}${ARCH_LIBDIR}
	${RUN}${LN} -fs ${X11_LIBDIR}/libX11.so.6 ${DESTDIR}${ARCH_LIBDIR}/jli
	${RUN}${LN} -fs ${X11_LIBDIR}/libXext.so.6 ${DESTDIR}${ARCH_LIBDIR}
	${RUN}${LN} -fs ${X11_LIBDIR}/libXi.so.6 ${DESTDIR}${ARCH_LIBDIR}
	${RUN}${LN} -fs ${X11_LIBDIR}/libXt.so.6 ${DESTDIR}${ARCH_LIBDIR}
	${RUN}${LN} -fs ${X11_LIBDIR}/libXtst.so.6 ${DESTDIR}${ARCH_LIBDIR}
.  if ${EMUL_OPSYS} == "linux"
	${RUN}${LN} -fs ${ALSA_LIBDIR}/libasound.so.2 ${DESTDIR}${ARCH_LIBDIR}
	${RUN}${LN} -fs ${ODBC_LIBDIR}/libodbc.so ${DESTDIR}${ARCH_LIBDIR}
	${RUN}${LN} -fs ${ODBC_LIBDIR}/libodbcinst.so ${DESTDIR}${ARCH_LIBDIR}
.  endif

PLIST.native=	yes
.endif

post-extract:
	${MKDIR} ${WRKSRC}/.systemPrefs
	${TOUCH} ${WRKSRC}/.systemPrefs/.system.lock
	${TOUCH} ${WRKSRC}/.systemPrefs/.systemRootModFile

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

pre-install:
	# This file is generated the *first* time the package is built on a box
	${RM} -f ${WRKSRC}/lib/servicetag/registration.xml
.if !empty(PKG_OPTIONS:Moracle-jre-jce)
	cd ${WRKDIR}/UnlimitedJCEPolicyJDK8 ; pax -rw -pe -v . ${WRKSRC}/lib/security
.endif

#
# re-create sfiles.mk from properties and config files
#
makesfiles:	extract
	${ECHO} >  ${SFILES_MK:Q} '#	$$Net''BSD$$'
	${ECHO} >> ${SFILES_MK:Q} '#'
	${ECHO} >> ${SFILES_MK:Q} '# Created with "make makesfiles"'
	${ECHO} >> ${SFILES_MK:Q} '# Do not edit this file manually!'
	${ECHO} >> ${SFILES_MK:Q} '#'
	cd ${WRKSRC}/lib && ${FIND} * -name fontconfig.\* -o		\
		-name \*.properties -o -name \*.properties.\?\? -o	\
		-name \*.cfg -o -name \*.security |			\
	${SED} 's/^/SFILES+=	/' >> ${PKGDIR}/${SFILES_MK:Q}

.include "../../mk/bsd.pkg.mk"
