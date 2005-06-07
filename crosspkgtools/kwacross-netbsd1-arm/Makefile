# $NetBSD: Makefile,v 1.2 2005/06/07 07:11:12 kristerw Exp $

DISTNAME=	kwacross-netbsd1-arm-20050605
CATEGORIES=     crosspkgtools
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-1.6.2/source/sets/
EXTRACT_SUFX=	.tgz
DISTFILES=	 ${DISTNAME}${EXTRACT_SUFX} \
		gnusrc.tgz sharesrc.tgz src.tgz syssrc.tgz

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.df.lth.se/~cato/kwacross/
COMMENT=	Simulator for running NetBSD/arm programs

DIST_SUBDIR=	kwacross-netbsd-1.6.2
SITES_kwacross-netbsd1-arm-20050605.tgz=http://www.df.lth.se/~cato/kwacross/distfiles/

GNU_CONFIGURE=  yes
CONFIGURE_ENV+=	ac_cv_path_BSHELL="/bin/sh"

# Where the target's file system is located.
#
# Note: must not have '/' at the end.
NBSIM_FILESYSTEM_PATH?=	"${PREFIX}/crossfs"

# Where to find the NetBSD cross tools.
NBSIM_TOOL_PATH=	"${PREFIX}/libexec/kwacrosstools-netbsd1-arm"

MAKE_FLAGS=	KWADEFS="-DPKGPREFIX=\\\"${PREFIX}\\\" -DEMUL_BASEDIR=\\\"${NBSIM_FILESYSTEM_PATH}\\\" -DTOOL_PATH=\\\"${NBSIM_TOOL_PATH}\\\" -DSIMPREFIX=\\\"${NBSIM_TOOL_PATH}\\\""

MACHINES=	acorn26 acorn32 cats evbarm hpcarm netwinder shark

post-build:
.	for machine in ${MACHINES}
	  ${SED} -e "s|@EMUL_HW_MACHINE@|${machine}|g"		\
		 -e "s|@TOOL_PATH@|${NBSIM_TOOL_PATH}|g"	\
		 ${WRKSRC}/files/nbsimsh			\
			> ${WRKSRC}/files/kwacrosssh-netbsd1-${machine}
	  ${SED} -e "s|@EMUL_HW_MACHINE@|${machine}|g"		\
		 -e "s|@TOOL_PATH@|${NBSIM_TOOL_PATH}|g"	\
		 ${WRKSRC}/files/nbsimmake			\
			> ${WRKSRC}/files/kwacrossmake-netbsd1-${machine}
.	endfor

do-install:
	cd ${WRKDIR}/usr/src && \
		./build.sh -T ${NBSIM_TOOL_PATH} -m shark -o -u -t
	${RM} -rf \
		${NBSIM_TOOL_PATH}/share \
		${NBSIM_TOOL_PATH}/man \
		${NBSIM_TOOL_PATH}/info \
		${NBSIM_TOOL_PATH}/include \
		${NBSIM_TOOL_PATH}/bin/nb*
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/sim/arm/run \
		${NBSIM_TOOL_PATH}/bin/netbsdsim-arm
	${INSTALL_PROGRAM} ${WRKSRC}/make/nbmake \
		${NBSIM_TOOL_PATH}/bin/nbsimmake-arm
	${INSTALL_PROGRAM} ${WRKSRC}/sh/sh \
		${NBSIM_TOOL_PATH}/bin/nbsimsh-arm
	${INSTALL_DATA_DIR} ${NBSIM_FILESYSTEM_PATH}
.	for machine in ${MACHINES}
	  ${INSTALL_SCRIPT} ${WRKSRC}/files/kwacrossmake-netbsd1-${machine} \
		${PREFIX}/bin
	  ${INSTALL_SCRIPT} ${WRKSRC}/files/kwacrosssh-netbsd1-${machine} \
		${PREFIX}/bin
.	endfor

.include "../../mk/bsd.pkg.mk"
