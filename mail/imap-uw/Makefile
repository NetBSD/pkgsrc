# $NetBSD: Makefile,v 1.24 2001/02/09 17:24:49 jlam Exp $

DISTNAME=       imap-2000c
PKGNAME=        imap-uw-2000c
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.washington.edu/imap/

USE_LIBTOOL=	# defined
USE_SSL=	# defined
NO_CONFIGURE=	# defined

INST_PROG=	${LIBTOOL} ${INSTALL_PROGRAM}
INST_LIB=	${LIBTOOL} ${INSTALL_DATA}
INC_DIR=	${PREFIX}/include/c-client
LIB_DIR=	${PREFIX}/lib
DOC_DIR=	${PREFIX}/share/doc/imap-uw

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ALL_TARGET=	gso
.else
ALL_TARGET=	neb
.endif

# CCLIENT_MBOX_FMT is the default format used by c-client programs for new
# mailbox creation.  Check the UW IMAP documentation for more details
# regarding the pros and cons of the various mailbox formats.
#
# Possible values: mbox, mbx, mh, mmdf, mtx, mx, news, phile, tenex, unix
# Default: unix
#
CCLIENT_MBOX_FMT?=	unix

CCLIENT_INCS=	c-client.h env.h env_unix.h flstring.h fs.h ftl.h	\
		imap4r1.h linkage.c linkage.h mail.h misc.h netmsg.h	\
		newsrc.h nl.h nntp.h osdep.h pop3.h rfc822.h smtp.h	\
		tcp.h utf8.h
CCLIENT_LIB=	libc-client.la
CCLIENT_LIBS=	libc-client.a libc-client.la libc-client.so		\
		libc-client.so.${CCLIENT_MAJOR}.${CCLIENT_MINOR}	\
		libc-client.so.${CCLIENT_MAJOR}
CCLIENT_MAJOR=	4
CCLIENT_MINOR=	1
CCLIENT_MFILES=	src/imapd/Makefile					\
		src/ipopd/Makefile					\
		src/mtest/Makefile					\
		src/osdep/unix/Makefile

PLIST_SUBST+=	CCLIENT_MAJOR="${CCLIENT_MAJOR}"
PLIST_SUBST+=	CCLIENT_MINOR="${CCLIENT_MINOR}"

MANFILES=	src/imapd/imapd.8c src/ipopd/ipopd.8c

MAKE_ENV+=	SSLDIR="${SSLBASE}"
MAKE_ENV+=	SSLCERTS="${SSLCERTS}"
MAKE_ENV+=	CCLIENT_MAJOR="${CCLIENT_MAJOR}"
MAKE_ENV+=	CCLIENT_MINOR="${CCLIENT_MINOR}"
MAKE_ENV+=	CREATEPROTO=${CCLIENT_MBOX_FORMAT}proto

ALL_TARGET+=	CC="${LIBTOOL} ${CC}"
ALL_TARGET+=	EXTRACFLAGS="${CFLAGS}"
ALL_TARGET+=	SPECIALAUTHENTICATORS="ssl"

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

do-install:
	${INSTALL_DATA_DIR} ${INC_DIR}
	cd ${WRKSRC}/c-client; ${INSTALL_DATA} ${CCLIENT_INCS} ${INC_DIR}
	${INST_LIB} ${WRKSRC}/c-client/${CCLIENT_LIB} ${LIB_DIR}
	cd ${LIB_DIR}; for file in ${CCLIENT_LIBS}; do		\
		f=`echo $${file} | ${SED} "s|libc-client|libimapuw|g"`;	\
		[ -f $${file} ] && ${LN} -sf $${file} $${f};		\
	done
	${INST_PROG} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/mtest/mtest ${PREFIX}/sbin
	${LN} -sf ../../libexec/imapd ${PREFIX}/sbin/rimapd
	${INSTALL_MAN} ${WRKSRC}/src/imapd/imapd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/ipopd/ipopd.8 ${PREFIX}/man/man8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop2d.8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop3d.8
	${CP} -R ${WRKSRC}/docs ${DOC_DIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOC_DIR}
	${CHMOD} -R a=rX ${DOC_DIR}

.include "../../mk/bsd.pkg.mk"
