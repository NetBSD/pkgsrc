# $NetBSD: Makefile,v 1.1.1.1 1999/10/28 00:02:08 jlam Exp $
#

DISTNAME=	Fortify-1.4.5-unix-src
PKGNAME=	fortify-1.4.5
CATEGORIES=	security www
MASTER_SITES=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.sage-au.org.au/pub/network/security/fortify/ \
		ftp://ftp.gns.com.br/pub/fortify/ \
		ftp://ftp.linux.hr/pub/fortify/ \
		ftp://ftp.funet.fi/pub/crypt/mirrors/fortify/ \
		ftp://ftp.win.or.jp/pub/network/security/fortify/ \
		http://www.hensa.ac.uk/mirrors/ftp.fortify.net/pub/Fortify/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fortify.net/

#LICENSE=	fee-based-commercial-use

INSTALL_DIRS=	alpha-dec-osf2.0 alpha-dec-osf3.2 alpha-dec-osf4.0 \
		mips-sgi-irix5.2 mips-sgi-irix5.3 mips-sgi-irix6.2 \
		ppc-unknown-linux2.0 \
		sparc-sun-solaris2.3 sparc-sun-solaris2.4 \
		sparc-sun-solaris2.5.1 sparc-sun-sunos4.1.3_U1 \
		x86-bsdi-bsd x86-bsdi-bsd2 \
		x86-sun-solaris2.4 x86-sun-solaris2.5.1 \
		x86-unknown-bsd x86-unknown-freebsd \
		x86-unknown-linux-elf x86-unknown-linux1.2 \
		x86-unknown-linux2.0 x86-unknown-linux2.0_glibc2 \
		x86-unknown-linux2.0_libc5 x86-unknown-linux2.2 \
		languages

post-extract:
	cd ${WRKSRC}; ${RMDIR} */bin

do-build:
	cd ${WRKSRC}/src/common; \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	cd ${WRKSRC}/src/cmdline; \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		${FILESDIR}/fortify.sh > ${WRKDIR}/fortify.sh
	${INSTALL_SCRIPT} ${WRKDIR}/fortify.sh ${PREFIX}/bin/fortify
	${INSTALL_PROGRAM} ${WRKSRC}/src/cmdline/fortify ${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/share/fortify
.for DIR in ${INSTALL_DIRS}
	cd ${WRKSRC}; ${PAX} -rw ${DIR} ${PREFIX}/share/fortify
.endfor
	${INSTALL_DATA} ${WRKSRC}/Index ${PREFIX}/share/fortify
	${LN} -sf languages/English ${PREFIX}/share/fortify/Messages
	${CHMOD} -R go-w ${PREFIX}/share/fortify
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/fortify
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fortify
	${INSTALL_DATA} ${WRKSRC}/README.html ${PREFIX}/share/doc/fortify
	cd ${WRKSRC}; ${PAX} -rw images ${PREFIX}/share/doc/fortify
	${CHMOD} -R go-w ${PREFIX}/share/doc/fortify
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/fortify

.include "../../mk/bsd.pkg.mk"
