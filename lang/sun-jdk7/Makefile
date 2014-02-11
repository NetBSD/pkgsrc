# $NetBSD: Makefile,v 1.14 2014/02/11 09:12:12 obache Exp $

# Note: This must be kept in sync with the sun-jre7 package
# Note: make sure you include sums for both the x86_64 and the x86_32
# in distinfo (make makesum will eat one of them)

DISTNAME=	jdk-7u51-${DIST_OS}-${DIST_ARCH}
PKGNAME=	sun-jdk7-7.0.51
MASTER_SITES=	# empty

LICENSE=	oracle-binary-code-license

DOWNLOAD_NAME=	Java Development Kit (JDK) 7u51

DEPENDS+=	${PKGNAME_NOREV:S/jdk/jre/}*:../../lang/sun-jre7

WRKSRC=		${WRKDIR}/jdk1.7.0_51
JAVA_WRAPPERS=	appletviewer apt extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver

MAKE_JOBS_SAFE=	no

.include "../../lang/sun-jre7/Makefile.common"

.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
CHECK_SHLIBS_SUPPORTED=	no
.endif

# The 64-bit Solaris downloads for some inexplicable reason only contain
# the additional 64-bit files, and you need the main 32-bit file too.
.if ${EMUL_OPSYS} == "solaris" && ${EMUL_ARCH} == "x86_64"
DISTFILES=	${DEFAULT_DISTFILES} ${DEFAULT_DISTFILES:S/x64/i586/}
.endif

PLIST_SRC=	PLIST.${DIST_OS}-${EMUL_ARCH}
PLIST_SUBST+=	JAVA_ARCH="${JAVA_ARCH}"

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
	${CHMOD} -x \
		${WRKSRC}/db/bin/NetworkServerControl.bat \
		${WRKSRC}/db/bin/dblook.bat \
		${WRKSRC}/db/bin/derby_common.bat \
		${WRKSRC}/db/bin/ij.bat \
		${WRKSRC}/db/bin/setEmbeddedCP.bat \
		${WRKSRC}/db/bin/setNetworkClientCP.bat \
		${WRKSRC}/db/bin/setNetworkServerCP.bat \
		${WRKSRC}/db/bin/startNetworkServer.bat \
		${WRKSRC}/db/bin/stopNetworkServer.bat \
		${WRKSRC}/db/bin/sysinfo.bat

.include "../../mk/bsd.pkg.mk"
