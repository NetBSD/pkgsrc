# $NetBSD: Makefile,v 1.53.2.1 2003/02/17 04:28:31 agc Exp $

DISTNAME=       imap-2002b
PKGNAME=        imap-uw-2002.2
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.washington.edu/imap/
COMMENT=	University of Washington's IMAP, POP2, and POP3 servers

USE_BUILDLINK2=	# defined
USE_LIBTOOL=	# defined

INST_PROG=	${PKGLIBTOOL} ${INSTALL_PROGRAM}
INST_LIB=	${PKGLIBTOOL} ${INSTALL_DATA}
INC_DIR=	${PREFIX}/include/c-client
LIB_DIR=	${PREFIX}/lib
DOC_DIR=	${PREFIX}/share/doc/imap-uw

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ALL_TARGET=	gso
.elif ${OPSYS} == "Linux"
ALL_TARGET=	lrh
.elif ${OPSYS} == "Darwin"
ALL_TARGET=	osx
.else
ALL_TARGET=	neb
.if defined(USE_KERBEROS) && (${USE_KERBEROS} != "no")
PKG_USE_KERBEROS=	#defined
ALL_TARGET+=	EXTRAAUTHENTICATORS="gss"
.endif
.endif

BUILD_DEFS+=	IMAP_UW_CCLIENT_MBOX_FMT IMAP_UW_NO_CLEARTEXT
CCLIENT_INCS=	c-client.h env.h env_unix.h flstring.h fs.h ftl.h	\
		imap4r1.h linkage.c linkage.h mail.h misc.h netmsg.h	\
		newsrc.h nl.h nntp.h osdep.h pop3.h rfc822.h smtp.h	\
		tcp.h utf8.h
CCLIENT_LIB=	libc-client.la
CCLIENT_PICLIB=	libc-client_pic.a
CCLIENT_MAJOR=	4
CCLIENT_MINOR=	1
CCLIENT_MFILES=	src/imapd/Makefile					\
		src/ipopd/Makefile					\
		src/mtest/Makefile					\
		src/osdep/unix/Makefile

PLIST_SUBST+=	CCLIENT_MAJOR="${CCLIENT_MAJOR}"
PLIST_SUBST+=	CCLIENT_MINOR="${CCLIENT_MINOR}"

MANFILES=	src/imapd/imapd.8c src/ipopd/ipopd.8c

MAKE_ENV+=	SSLDIR=${SSLBASE:Q}
MAKE_ENV+=	SSLCERTS=${SSLCERTS:Q}
MAKE_ENV+=	CCLIENT_MAJOR=${CCLIENT_MAJOR:Q}
MAKE_ENV+=	CCLIENT_MINOR=${CCLIENT_MINOR:Q}
MAKE_ENV+=	CREATEPROTO=${IMAP_UW_CCLIENT_MBOX_FMT:Q}proto

ALL_TARGET+=	CC="${PKGLIBTOOL} ${CC}"
ALL_TARGET+=	EXTRACFLAGS="${CFLAGS}"
ALL_TARGET+=	EXTRALDFLAGS="${LDFLAGS}"
.if defined(IMAP_UW_NO_CLEARTEXT) && ${IMAP_UW_NO_CLEARTEXT} == "YES"
ALL_TARGET+=	SSLTYPE="nopwd"
.elif !defined(IMAP_UW_NO_SSL) || ${IMAP_UW_NO_SSL} != "YES"
ALL_TARGET+=	SPECIALAUTHENTICATORS="ssl"
ALL_TARGET+=	SSLTYPE="unix"
.endif

# reduce optimization level on alpha to avoid compiler bugs
.if ${OPSYS} == "NetBSD"
.  if (${MACHINE_ARCH} == "alpha")
CPPFLAGS:=      ${CPPFLAGS:C/-O[0-9]*/-O/g}
CFLAGS:=        ${CFLAGS:C/-O[0-9]*/-O/g}
CONFIGURE_ENV+= CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+= CFLAGS="${CFLAGS}"
.  endif
.endif

post-extract:
	#
	# Change references to the built library to ${CCLIENT_LIB}.
	#
	cd ${WRKSRC}; for file in ${CCLIENT_MFILES}; do			\
		${MV} -f $${file} $${file}.orig;			\
		${SED}	-e "s|c-client.a|${CCLIENT_LIB}|g"		\
			$${file}.orig > $${file};			\
		${RM} -f $${file}.orig;					\
	done
	#
	# Correct hardcoded paths in man pages.
	#
	cd ${WRKSRC}; for file in ${MANFILES}; do			\
		f=`echo $${file} | ${SED} "s|\(.*\)\.\([0-9]\).*|\1.\2|"`; \
		${SED}	-e "s|/usr/etc/imapd|${PREFIX}/libexec/imapd|g"	\
			-e "s|/etc/rimapd|${PREFIX}/sbin/rimapd|g"	\
			-e "s|/usr/etc/ipop2d|${PREFIX}/libexec/ipop2d|g" \
			-e "s|/usr/etc/ipop3d|${PREFIX}/libexec/ipop3d|g" \
			$${file} > $${f};				\
	done

# Generate _pic.a library from shared objects.
#
post-build:
	cd ${WRKSRC}/c-client;						\
	${PKGLIBTOOL} ${CC} -o ${CCLIENT_PICLIB:.a=.la} *.lo

do-install:
	${INSTALL_DATA_DIR} ${INC_DIR}
	cd ${WRKSRC}/c-client; ${INSTALL_DATA} ${CCLIENT_INCS} ${INC_DIR}
	${INST_LIB} ${WRKSRC}/c-client/${CCLIENT_LIB} ${LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/c-client/.libs/${CCLIENT_PICLIB} ${LIB_DIR}
	${RANLIB} ${LIB_DIR}/${CCLIENT_PICLIB}
	cd ${LIB_DIR}; for file in libc-client.*; do			\
		f=`echo $${file} | ${SED} "s|libc-client|libimapuw|g"`;	\
		${TEST} -f $${file} && ${LN} -sf $${file} $${f};	\
	done
	${INST_PROG} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/mtest/mtest ${PREFIX}/sbin
	${LN} -sf ../libexec/imapd ${PREFIX}/sbin/rimapd
	${INSTALL_MAN} ${WRKSRC}/src/imapd/imapd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/ipopd/ipopd.8 ${PREFIX}/man/man8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop2d.8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop3d.8
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${CP} -R ${WRKSRC}/docs/* ${DOC_DIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOC_DIR}
	${CHMOD} -R a=rX ${DOC_DIR}

.if !defined(IMAP_UW_NO_SSL) || ${IMAP_UW_NO_SSL} != "YES"
.include "../../security/openssl/buildlink2.mk"
.endif
.include "../../mk/bsd.pkg.mk"
