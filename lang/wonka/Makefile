# $NetBSD: Makefile,v 1.1.1.1 2002/11/01 10:49:33 skrll Exp $
#

DISTNAME=	wonka-src-0.9.4-release
PKGNAME=	wonka-0.9.4
CATEGORIES=	lang
MASTER_SITES=	http://wonka.acunia.com/

MAINTAINER=	skrll@netbsd.org
HOMEPAGE=	http://wonka.acunia.com/download.html
COMMENT=	BSD-licenced java virtual machine

BUILD_DEPENDS+=	acunia-jam>=1.0nb1:../../devel/acunia-jam
BUILD_DEPENDS+=	jamjar-[0-9]*:../../archivers/jamjar
BUILD_DEPENDS+=	jikes-1.12:../../lang/jikes112
BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

USE_BUILDLINK2=	# defined
USE_X11=	# defined

JVM_HOME=	${LOCALBASE}/java/${PKGBASE}
NO_MTREE=	# defined, since we change PREFIX below

WRKSRC=		${WRKDIR}/open-wonka

SEDFILES=	\
	${WRKSRC}/wonka/resource/system/system.properties		\
	${WRKSRC}/Configuration/cpu/arm					\
	${WRKSRC}/Configuration/cpu/x86

post-extract:
	${MKDIR} -p ${WRKSRC}/class/doclet/com/acunia/doclet
	${SED}	-e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/pkgsrc 					\
		> ${WRKSRC}/Configuration/wonka/pkgsrc

post-patch:
	for file in ${SEDFILES}; do					\
		${SED}	-e "s|@PREFIX@|${PREFIX}|g"			\
			-e "s|@CC@|cc|g"				\
			-e "s|@LD@|ld|g"				\
			-e "s|@AS@|as|g"				\
			-e "s|@AR@|ar|g"				\
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
			-sAWT_DEVICE=xsim				\
			-sDEBUG=false

do-build:
	${JAM_COMMAND}

do-install:
	${JAM_COMMAND} install
	${RM} -f ${PREFIX}/bin/java
	${LN} -sf wonka ${PREFIX}/bin/java

test:	install
	cd ${WRKDIR} && LD_LIBRARY_PATH=${PREFIX}/test			\
		${PREFIX}/bin/wonka gnu.testlet.TestRunner

.include "../../mk/bsd.pkg.mk"

# This needs to be after bsd.pkg.mk 
PREFIX=		${JVM_HOME}
