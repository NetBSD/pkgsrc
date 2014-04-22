# $NetBSD: java.mk,v 1.1 2014/04/22 20:46:41 ryoon Exp $

LANGS+=			java
USE_TOOLS+=		perl

# Add the  Eclipse Java compiler for to parse `.java' source files.
ECJ_JAR=		ecj-4.5.jar
SITES.${ECJ_JAR}=	ftp://sourceware.org/pub/java/
DISTFILES+=		${ECJ_JAR}
CONFIGURE_ARGS+=	--with-ecj-jar=${DISTDIR:Q}/${ECJ_JAR:Q}

JAVA_NAME=		${GCC_PKGNAME}
JAVA_HOME=		${PREFIX}/java/${JAVA_NAME}
.if !empty(PKGPATH:Mlang/gcc48-java)
JAVA_WRAPPERS=		appletviewer jar jarsigner java javah keytool \
			native2ascii orbd rmic rmid rmiregistry serialver \
			tnameserv
.endif

JAVA_ARCH=		${MACHINE_ARCH:S/x86_64/amd64/}

PLIST_SUBST+=		JAVA_NAME=${JAVA_NAME:Q}
PLIST_SUBST+=		JAVA_ARCH=${JAVA_ARCH:Q}

# Create a JPackage compatible SDK environment.
CONFIGURE_ARGS+=	--enable-java-home
CONFIGURE_ARGS+=	--with-os-directory=${LOWER_OPSYS:Q}
CONFIGURE_ARGS+=	--with-arch-directory=${JAVA_ARCH:Q}
CONFIGURE_ARGS+=	--with-jvm-root-dir=${JAVA_HOME:Q}
CONFIGURE_ARGS+=	--with-java-home=${JAVA_HOME:Q}

REPLACE_PYTHON=		libjava/contrib/aot-compile.in

USE_TOOLS+=		unzip zip:run gmake:run
CONFIGURE_ARGS+=	--with-system-zlib

# libjava/contrib/aotcompile.py.in stores the path to a 'make' program so
# we need to make sure we give it the installed 'make' and not the tool
# wrapped one.
CONFIGURE_ENV+=		PKGSRC_MAKE=${TOOLS_PATH.gmake}
MAKE_ENV+=		PKGSRC_MAKE=${TOOLS_PATH.gmake}

# fastjar-0.93 from pkgsrc/archivers/fastjar seems to trigger a build
# failure (seen on NetBSD-5.0/i386) when building java.  So in case
# the fastjar package is installed, make sure the configure script
# doesn't pick it up.
CONFIGURE_ENV+=		JAR=no
MAKE_ENV+=		JAR=no
MAKE_ENV+=		ac_cv_prog_JAR=no

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/java-env.mk"
