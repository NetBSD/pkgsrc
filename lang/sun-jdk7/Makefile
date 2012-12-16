# $NetBSD: Makefile,v 1.3 2012/12/16 13:58:25 ryoon Exp $

DISTNAME=	jdk-7u10-linux-${DIST_ARCH}
PKGNAME=	sun-jdk7-7.0.10
MASTER_SITES=	# empty

LICENSE=	oracle-binary-code-license

DOWNLOAD_NAME=	Java Development Kit (JDK) 7u10

DEPENDS+=	${PKGNAME_NOREV:S/jdk/jre/}*:../../lang/sun-jre7

WRKSRC=		${WRKDIR}/jdk1.7.0_10
JAVA_WRAPPERS=	appletviewer apt extcheck idlj jar jarsigner \
		javac javadoc javah javap jdb rmic serialver

MAKE_JOBS_SAFE=	no

.include "../../lang/sun-jre7/Makefile.common"

.if !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
CHECK_SHLIBS_SUPPORTED=	no
.endif

PLIST_SRC=	PLIST.linux-${EMUL_ARCH}

# Remove parts that are in common with the JRE
#
post-extract:
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
