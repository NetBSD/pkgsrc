# $NetBSD: Makefile,v 1.1.1.1 2000/08/25 01:07:29 jlam Exp $

DISTNAME=		wordperfect-personal-8
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.download.com/pub/win95/business/GUILG/ \
			ftp://ftp.cdrom.com/pub/simtelnet/cnet/win95/business/GUILG/
DISTFILES=		GUILG00.GZ

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://linux.corel.com/products/wp8/

DEPENDS+=		suse_linux>=6.1:../../emulators/suse_linux

LICENSE=		no-commercial-use
MIRROR_DISTFILE=	no
RESTRICTED=		"No re-distribution without agreement from Corel(R)"
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-*-i386
IS_INTERACTIVE=		# defined

DIST_SUBDIR=		${DISTNAME}
INSTALL_FILE=		${WRKDIR}/INSTALL
NO_WRKSUBDIR=		# defined
NO_CONFIGURE=		# defined

WPDIR=			lib/wordperfect

post-extract:
	${CP} ${FILESDIR}/uname ${WRKDIR}
	${CHMOD} +x ${WRKDIR}/uname

# Extract all the archives and set the defaults for the installation process.
#
pre-build:
	cd ${WRKDIR}; for file in *_*; do \
		${GTAR} -xf $$file; \
	done
	${RM} -f ${WRKDIR}/shared/wpdata
	${SED} -e "s,@WRKDIR@,${WRKDIR},g" -e "s,@WPDIR@,${WPDIR},g" \
		< ${FILESDIR}/wpdata > ${WRKDIR}/shared/wpdata
	@${ECHO_MSG} ""
	@${ECHO_MSG} "-------------------------------------------------------"
	@${ECHO_MSG} " Now running the WordPerfect(R) installation script.   "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " After the installation completes, the WordPerfect     "
	@${ECHO_MSG} " program will start to initialize the configuration.   "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " If you have a product license key, you may enter it   "
	@${ECHO_MSG} " or simply press "Enter key later" to continue.        "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Afterwords, please exit WordPerfect to continue the   "
	@${ECHO_MSG} " package installation.                                 "
	@${ECHO_MSG} "-------------------------------------------------------"
	@${ECHO_MSG} ""

# Always accept the defaults during installation.
#
do-build:
	cd ${WRKDIR}; \
	DISPLAY=""; export DISPLAY; \
	PATH="${WRKDIR}:${PATH}"; export PATH; \
	yes o | ./Runme
	([ ! -d ${HOME}/.wprc ] || ${MV} ${HOME}/.wprc ${HOME}/.wprc.$$$$; \
	 ${WRKDIR}/${WPDIR}/wpbin/xwp; \
	 ${RM} -rf ${HOME}/.wprc; \
	 [ ! -d ${HOME}/.wprc.$$$$ ] || ${MV} ${HOME}/.wprc.$$$$ ${HOME}/.wprc)

post-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" -e "s,@WPDIR@,${WPDIR},g" \
		< ${FILESDIR}/xwp > ${WRKDIR}/xwp
	${SED} -e "s,@WPDIR@,${WPDIR},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/xwp ${PREFIX}/bin/xwp
	cd ${WRKDIR}/lib; ${PAX} -rw wordperfect ${PREFIX}/lib
	${CHMOD} -R go-w ${PREFIX}/${WPDIR}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
