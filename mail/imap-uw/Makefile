# $NetBSD: Makefile,v 1.95 2005/06/16 06:58:02 jlam Exp $
# ATTENTION:
# The Kerberos support in this software is known to be problematic. If you
# upgrade this package you *must* test it on a system with Kerberos libraries
# but not running Kerberos before committing the changes.

DISTNAME=       imap-2004c1
PKGNAME=        imap-uw-2004c1
PKGREVISION=	2
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.washington.edu/imap/
COMMENT=	University of Washington's IMAP, POP2, and POP3 servers

USE_LIBTOOL=	# defined

INST_PROG=	${LIBTOOL} ${INSTALL_PROGRAM}
INST_LIB=	${LIBTOOL} ${INSTALL_LIB}
INC_DIR=	${PREFIX}/include/c-client
LIB_DIR=	${PREFIX}/lib
DOC_DIR=	${PREFIX}/share/doc/imap-uw

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_TARGET=	gso
.elif ${OPSYS} == "Linux"
BUILD_TARGET=	slx
.elif ${OPSYS} == "Darwin"
BUILD_TARGET=	osx
.elif ${OPSYS} == "IRIX"
.  if ${OS_VERSION} >= 6.5
BUILD_TARGET=	sg6
.  else
BUILD_TARGET=	sgi
.  endif
.else
# USE_KERBEROS=no is explicitly set on NetBSD 1.x due to interoperability
# issues with later versions of OpenSSL (e.g. 0.9.7)
BUILD_TARGET=	neb
.  if !empty(MACHINE_PLATFORM:MNetBSD-1.*)
USE_KERBEROS=	no
.  endif
.  if defined(USE_KERBEROS) && ${USE_KERBEROS} != "no"
PKG_USE_KERBEROS=	# defined
BUILD_TARGET+=	EXTRAAUTHENTICATORS="gss"
.    if !empty(MACHINE_PLATFORM:MNetBSD-1.5*)
# NetBSD-1.5 didn't have "des_new_random_key" in libcrypto
MAKE_ENV+=	GSS_EXTRA_LDFLAGS="-ldes"
.    endif
.  endif
.endif

BUILD_DEFS+=	IMAP_UW_CCLIENT_MBOX_FMT IMAP_UW_NO_CLEARTEXT IMAP_UW_USE_WHOSON
CCLIENT_INCS=	c-client.h env.h env_unix.h flocksim.h flstring.h	\
		fs.h ftl.h imap4r1.h linkage.c linkage.h mail.h misc.h	\
		netmsg.h newsrc.h nl.h nntp.h osdep.h rfc822.h		\
		smtp.h tcp.h utf8.h
CCLIENT_LIB=	libc-client.la
CCLIENT_PICLIB=	libc-client_pic.a
CCLIENT_MAJOR=	4
CCLIENT_MINOR=	1
CCLIENT_MFILES=	src/imapd/Makefile					\
		src/ipopd/Makefile					\
		src/mtest/Makefile					\
		src/osdep/unix/Makefile

MESSAGE_SUBST+=	SSLCERTS="${SSLCERTS}"
MESSAGE_SUBST+=	SSLKEYS="${SSLKEYS}"
PLIST_SUBST+=	CCLIENT_MAJOR="${CCLIENT_MAJOR}"
PLIST_SUBST+=	CCLIENT_MINOR="${CCLIENT_MINOR}"

MANFILES=	src/imapd/imapd.8 src/ipopd/ipopd.8

MAKE_ENV+=	SSLDIR=${SSLBASE:Q}
MAKE_ENV+=	SSLCERTS=${SSLCERTS:Q}
MAKE_ENV+=	SSLKEYS=${SSLKEYS:Q}
MAKE_ENV+=	CCLIENT_MAJOR=${CCLIENT_MAJOR:Q}
MAKE_ENV+=	CCLIENT_MINOR=${CCLIENT_MINOR:Q}
MAKE_ENV+=	CREATEPROTO=${IMAP_UW_CCLIENT_MBOX_FMT:Q}proto

BUILD_TARGET+=	CC="${LIBTOOL} ${CC}"
.if defined(IMAP_UW_USE_WHOSON) && ${IMAP_UW_USE_WHOSON} == "YES"
BUILD_TARGET+=	EXTRALDFLAGS="${LDFLAGS} -lwhoson"
BUILD_TARGET+=	EXTRACFLAGS="${CFLAGS} -DUSE_WHOSON"
.else
BUILD_TARGET+=	EXTRALDFLAGS="${LDFLAGS}"
BUILD_TARGET+=	EXTRACFLAGS="${CFLAGS}"
.endif
.if defined(IMAP_UW_NO_CLEARTEXT) && ${IMAP_UW_NO_CLEARTEXT} == "YES"
BUILD_TARGET+=	SSLTYPE="nopwd"
.elif !defined(IMAP_UW_NO_SSL) || ${IMAP_UW_NO_SSL} != "YES"
BUILD_TARGET+=	SPECIALAUTHENTICATORS="ssl"
BUILD_TARGET+=	SSLTYPE="unix"
.endif

# reduce optimization level on alpha to avoid compiler bugs
.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "alpha"
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
	cd ${WRKSRC}; for FILE in ${MANFILES}; do			\
		${CP} $${FILE} $${FILE}.broken;				\
		${SED}	-e "s|/usr/etc/imapd|${PREFIX}/libexec/imapd|g"	\
			-e "s|/etc/rimapd|${PREFIX}/sbin/rimapd|g"	\
			-e "s|/usr/etc/ipop2d|${PREFIX}/libexec/ipop2d|g" \
			-e "s|/usr/etc/ipop3d|${PREFIX}/libexec/ipop3d|g" \
			$${FILE}.broken > $${FILE};			\
	done

BUILD_DEFS+=	IMAP_UW_MAILSPOOLHOME

post-patch:
.if defined(IMAP_UW_MAILSPOOLHOME)
	cd ${WRKSRC}/src/osdep/unix &&					\
	${SED}	-e 's|@SPOOLDIR@|myhomedir ()|'				\
		-e 's|@MAILBOX@|"${IMAP_UW_MAILSPOOLHOME}"|'		\
		env_unix.c > env_unix.c.new &&				\
	${MV} -f env_unix.c.new env_unix.c
.else
	cd ${WRKSRC}/src/osdep/unix &&					\
	${SED}	-e 's|@SPOOLDIR@|MAILSPOOL|'				\
		-e 's|@MAILBOX@|myusername ()|'				\
		env_unix.c > env_unix.c.new &&				\
	${MV} -f env_unix.c.new env_unix.c
.endif

# Generate _pic.a library from shared objects.
#
post-build:
	cd ${WRKSRC}/c-client;						\
	${LIBTOOL} ${CC} -o ${CCLIENT_PICLIB:.a=.la} *.lo

do-install:
	${INSTALL_DATA_DIR} ${INC_DIR}
	cd ${WRKSRC}/c-client; ${INSTALL_DATA} ${CCLIENT_INCS} ${INC_DIR}
	${INSTALL_LIB_DIR} ${LIB_DIR}
	${INST_LIB} ${WRKSRC}/c-client/${CCLIENT_LIB} ${LIB_DIR}
	${INSTALL_LIB} ${WRKSRC}/c-client/.libs/${CCLIENT_PICLIB} ${LIB_DIR}
	${RANLIB} ${LIB_DIR}/${CCLIENT_PICLIB}
	cd ${LIB_DIR}; for file in libc-client.*; do			\
		case $$file in						\
		*.la)	;;						\
		*)							\
			f=`${ECHO} $${file} | ${SED} "s|libc-client|libimapuw|g"`; \
			${TEST} -f $${file} && ${LN} -f $${file} $${f};	\
			;;						\
		esac;							\
	done
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec
	${INSTALL_PROGRAM_DIR} ${PREFIX}/sbin
	${INST_PROG} ${WRKSRC}/mtest/mtest ${PREFIX}/sbin
	${LN} -sf ../libexec/imapd ${PREFIX}/sbin/rimapd
	${INSTALL_MAN_DIR} ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/imapd/imapd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/ipopd/ipopd.8 ${PREFIX}/man/man8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop2d.8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop3d.8
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${CP} -R ${WRKSRC}/docs/* ${DOC_DIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOC_DIR}
	${FIND} ${DOC_DIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DOC_DIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${INST_PROG} ${WRKSRC}/mailutil/mailutil ${PREFIX}/bin
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/src/mailutil/mailutil.1 ${PREFIX}/man/man1
	${INST_PROG} ${WRKSRC}/dmail/dmail ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/dmail/dmail.1 ${PREFIX}/man/man1
	${INST_PROG} ${WRKSRC}/mlock/mlock ${PREFIX}/bin
	${INST_PROG} ${WRKSRC}/tmail/tmail ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/tmail/tmail.1 ${PREFIX}/man/man1

.if !defined(IMAP_UW_NO_SSL) || ${IMAP_UW_NO_SSL} != "YES"
.include "../../security/openssl/buildlink3.mk"
.endif

.if defined(IMAP_UW_USE_WHOSON) && ${IMAP_UW_USE_WHOSON} == "YES"
.include "../../net/whoson/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
