# $NetBSD: Makefile,v 1.9 2003/11/11 07:55:14 wiz Exp $
#

DISTNAME=	Fortify-1.4.6-unix-src
PKGNAME=	fortify-1.4.6
CATEGORIES=	security www
MASTER_SITES=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.sage-au.org.au/pub/network/security/fortify/ \
		ftp://ftp.gns.com.br/pub/fortify/ \
		ftp://ftp.linux.hr/pub/fortify/ \
		ftp://ftp.funet.fi/pub/crypt/mirrors/fortify/ \
		ftp://ftp.win.or.jp/pub/network/security/fortify/ \
		http://www.mirror.ac.uk/sites/ftp.fortify.net/pub/Fortify/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fortify.net/
COMMENT=	Patches Netscape binary to provide 128-bit cryptography

LICENSE=	fee-based-commercial-use

FORTIFY_DIRS=	alpha-dec-osf2.0 \
		alpha-dec-osf3.2 \
		alpha-dec-osf4.0 \
		hppa1.1-hp-hpux10 \
		hppa1.1-hp-hpux1010 \
		hppa1.1-hp-hpux1020 \
		mips-sgi-irix5.2 \
		mips-sgi-irix5.3 \
		mips-sgi-irix6.2 \
		mips-sgi-irix6.5 \
		ppc-unknown-linux2.0 \
		ppc-unknown-linux2.2 \
		ppc_rs6000-ibm-aix4 \
		ppc_rs6000-ibm-aix41 \
		sparc-sun-solaris2.3 \
		sparc-sun-solaris2.4 \
		sparc-sun-solaris2.5.1 \
		sparc-sun-sunos4.1.3_U1 \
		x86-bsdi-bsd \
		x86-bsdi-bsd2 \
		x86-sun-solaris2.4 \
		x86-sun-solaris2.5.1 \
		x86-unknown-bsd \
		x86-unknown-freebsd \
		x86-unknown-linux-elf \
		x86-unknown-linux1.2 \
		x86-unknown-linux2.0 \
		x86-unknown-linux2.0_glibc2 \
		x86-unknown-linux2.0_libc5 \
		x86-unknown-linux2.2 \
		languages

post-extract:
	cd ${WRKSRC}; ${RMDIR} */bin

do-build:
	cd ${WRKSRC}/src/common; \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${ALL_TARGET}
	cd ${WRKSRC}/src/cmdline; \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} ${ALL_TARGET}

do-install:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		${FILESDIR}/fortify.sh > ${WRKDIR}/fortify.sh
	${INSTALL_SCRIPT} ${WRKDIR}/fortify.sh ${PREFIX}/bin/fortify
	${INSTALL_PROGRAM} ${WRKSRC}/src/cmdline/fortify ${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/share/fortify
.for DIR in ${FORTIFY_DIRS}
	cd ${WRKSRC} && ${PAX} -rw ${DIR} ${PREFIX}/share/fortify
.endfor
	${INSTALL_DATA} ${WRKSRC}/Index ${PREFIX}/share/fortify
	${LN} -sf languages/English ${PREFIX}/share/fortify/Messages
	${CHMOD} -R go-w ${PREFIX}/share/fortify
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/fortify
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fortify
	${INSTALL_DATA} ${WRKSRC}/README.html ${PREFIX}/share/doc/fortify
	cd ${WRKSRC} && ${PAX} -rw images ${PREFIX}/share/doc/fortify
	${CHMOD} -R go-w ${PREFIX}/share/doc/fortify
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/fortify

.include "../../mk/bsd.pkg.mk"
