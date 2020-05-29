# $NetBSD: Makefile,v 1.10 2020/05/29 10:57:22 abs Exp $

# Note: This must be kept in sync with the oracle-jre8 package
# Note: make sure you include sums for both the x86_64 and the x86_32
# in distinfo (make makesum will eat one of them)

DISTNAME=	jdk-8u${UPDATE_NUMBER}-${DIST_OS}-${DIST_ARCH}
PKGNAME=	oracle-jdk8-8.0.${UPDATE_NUMBER}
PKGREVISION=	1
MASTER_SITES=	# empty

LICENSE=	oracle-binary-code-license

DOWNLOAD_NAME=	Java Development Kit (JDK) 8u${UPDATE_NUMBER}

DEPENDS+=	${PKGNAME_NOREV:S/jdk/jre/}*:../../lang/oracle-jre8

WRKSRC=		${WRKDIR}/jdk1.8.0_${UPDATE_NUMBER}
JAVA_WRAPPERS=	appletviewer apt extcheck idlj jar jarsigner \
		javac javadoc javah javap jcmd jdb jhat rmic serialver jmap jps

MAKE_JOBS_SAFE=	no

.include "../../lang/oracle-jre8/Makefile.common"

PLIST_SRC=	PLIST.${DIST_OS}-${EMUL_ARCH}
PLIST_SUBST+=	JAVA_ARCH="${JAVA_ARCH}"

# Simplify distinfo generation
.if make(distinfo)
DISTFILES=	jdk-8u${UPDATE_NUMBER}-linux-i586.tar.gz
DISTFILES+=	jdk-8u${UPDATE_NUMBER}-linux-x64.tar.gz
DISTFILES+=	jdk-8u${UPDATE_NUMBER}-solaris-x64.tar.gz
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

# Remove parts that are in common with the JRE
#
post-extract:
	${MKDIR} ${WRKSRC}/lib/${JAVA_ARCH}
	${MV} ${WRKSRC}/jre/lib/${JAVA_ARCH}/libattach.so ${WRKSRC}/lib/${JAVA_ARCH}
	${MV} ${WRKSRC}/jre/lib/${JAVA_ARCH}/libsaproc.so ${WRKSRC}/lib/${JAVA_ARCH}
	common=`${AWK} '/^#.*/ { next } /^$$/ { next } { print }' ${FILESDIR}/common`; \
	cd ${WRKSRC}; for i in $$common; do				\
		if [ -d $$i ]; then					\
			${RM} -rf $$i;					\
		else							\
			${RM} -f $$i;					\
		fi;							\
	done
	${LN} -sf . ${WRKSRC}/jre

pre-install:
	# These files are generated the *first* time the package is built
	${RM} -f ${WRKSRC}/register.html
	${RM} -f ${WRKSRC}/register_ja.html
	${RM} -f ${WRKSRC}/register_zh_CN.html

.include "../../mk/bsd.pkg.mk"
