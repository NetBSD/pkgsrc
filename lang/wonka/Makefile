# $NetBSD: Makefile,v 1.16 2004/07/01 00:51:23 wiz Exp $
#

DISTNAME=	wonka-src-0.9.6-release
PKGNAME=	wonka-0.9.6
CATEGORIES=	lang java
MASTER_SITES=	http://wonka.acunia.com/

MAINTAINER=	skrll@NetBSD.org
HOMEPAGE=	http://wonka.acunia.com/download.html
COMMENT=	BSD-licenced java virtual machine

# This has only been ported to arm and x86 so far.
ONLY_FOR_PLATFORM=	*-*-i386 *-*-arm *-*-arm32

BUILD_DEPENDS+=	acunia-jam>=1.0nb1:../../devel/acunia-jam
BUILD_DEPENDS+=	jamjar-[0-9]*:../../archivers/jamjar
BUILD_DEPENDS+=	jikes>=1.18:../../lang/jikes
BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

WRKSRC=		${WRKDIR}/open-wonka
USE_BUILDLINK3=	yes
USE_X11=	# defined

JVM_HOME=	${PREFIX}/java/${PKGBASE}

SEDFILES=	\
	${WRKSRC}/tool/mauve/java/gnu/testlet/wonka/lang/ClassLoader/AcuniaClassLoaderTest.java \
	${WRKSRC}/tool/mauve/java/gnu/testlet/wonka/util/zip/GZIPInputStream/basic.java \
	${WRKSRC}/tool/mauve/java/gnu/testlet/wonkax/microedition/io/Connector/AcuniaConnectorTest.java \
	${WRKSRC}/wonka/resource/system/wonka.security \
	${WRKSRC}/tool/mauve/java/gnu/testlet/wonka/util/zip/GZIPInputStream/basic.java \
	${WRKSRC}/tool/mauve/java/gnu/testlet/wonka/lang/ClassLoader/AcuniaClassLoaderTest.java \
	${WRKSRC}/tool/mauve/java/gnu/testlet/wonka/io/Utf8Encoding/ReadReference.java \
	${WRKSRC}/tool/mauve/java/gnu/testlet/wonka/io/DataInputOutput/ReadReference.java \
	${WRKSRC}/tool/visualtest/java/com/acunia/wonka/test/awt/vte.properties \
	${WRKSRC}/wonka/resource/system/system.properties		\
	${WRKSRC}/Configuration/cpu/arm					\
	${WRKSRC}/Configuration/cpu/x86

post-extract:
	@${MKDIR} -p ${WRKSRC}/class/doclet/com/acunia/doclet
	@${SED}	-e "s|@PREFIX@|${JVM_HOME}|g"				\
		${FILESDIR}/pkgsrc 					\
		> ${WRKSRC}/Configuration/wonka/pkgsrc

post-patch:
	@for file in ${SEDFILES}; do					\
		${SED}	-e "s|@PREFIX@|${JVM_HOME}|g"			\
			-e "s|@CC@|${CC}|g"				\
			-e "s|@LD@|${LD}|g"				\
			-e "s|@AS@|${CC} -c|g"				\
			-e "s|@AR@|${AR}|g"				\
			-e "s|@RANLIB@|${RANLIB}|g"			\
			$${file} > $${file}.fixed &&			\
		${MV} -f $${file}.fixed $${file};			\
	done

MAKE_ENV+=	WONKA_TOP=${WRKSRC}
JAM_COMMAND=	\
	cd ${WRKSRC} && 						\
		${SETENV} ${MAKE_ENV}					\
		${LOCALBASE}/bin/jam					\
			-sWONKA_CONFIG=pkgsrc				\
			-sCPU=${LOWER_ARCH}				\
			-sHOSTOS=${LOWER_OPSYS}				\
			-sAWT_DEVICE=xsim

do-build:
	${JAM_COMMAND}

do-install:
	${JAM_COMMAND} install
	${RM} -f ${JVM_HOME}/bin/java
	${LN} -sf wonka ${JVM_HOME}/bin/java

test:	install
	cd ${WRKDIR} && LD_LIBRARY_PATH=${JVM_HOME}/test		\
		${JVM_HOME}/bin/wonka gnu.testlet.TestRunner

.include "../../mk/bsd.pkg.mk"
