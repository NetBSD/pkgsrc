# $NetBSD: Makefile,v 1.38 2001/05/03 00:24:12 itojun Exp $

DISTNAME=	postfix-20010228-pl02
PKGNAME=	postfix-20010228pl2
CATEGORIES=	mail
MASTER_SITES=	ftp://postfix.cloud9.net/official/

PATCHFILES=	postfix-20010228pl02-v6-20010503a.diff.gz \
		postfix-20010228release-ercpt.diff
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/ \
		ftp://ftp.gw.com/pub/people/kim/patches/
PATCH_DIST_STRIP+=	-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.postfix.org/
COMMENT=	postfix smtp server and tools

DIST_SUBDIR=	postfix

POSTFIX_SPOOL=	/var/spool/postfix

.include "../../mk/bsd.prefs.mk"
# automagically determines IPv6 support
BUILD_DEFS+=	USE_INET6

.if defined(POSTFIX_PCRE) && ${POSTFIX_PCRE} == YES
DEPENDS+=	pcre-2.08:../../devel/pcre
CFLAGS+=	-DHAS_PCRE -I${LOCALBASE}/include
AUXLIBS=	-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lpcre
MAKE_ENV+=	AUXLIBS="${AUXLIBS}"
.endif

BUILD_DEFS+=	POSTFIX_PCRE

PLIST_SRC=	${PKGDIR}/PLIST

ALL_TARGET=	#empty

pre-configure:
	${CP} ${WRKSRC}/conf/main.cf ${WRKSRC}/conf/main.cf.dist
	${CP} ${WRKSRC}/src/util/sys_defs.h ${WRKSRC}/src/util/sys_defs.h.dist
	${CP} ${WRKSRC}/INSTALL.sh ${WRKSRC}/INSTALL.sh.dist
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/conf/main.cf.dist \
	    > ${WRKSRC}/conf/main.cf
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/src/util/sys_defs.h.dist \
	    > ${WRKSRC}/src/util/sys_defs.h
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/INSTALL.sh.dist \
	    > ${WRKSRC}/INSTALL.sh

do-configure:
	(cd ${WRKSRC}; ${MAKE} makefiles)

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	    <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.postfix

pre-install:
	${INSTALL_DATA_DIR} /etc/postfix ${PREFIX}/share/postfix \
	    ${PREFIX}/share/doc/postfix ${PREFIX}/libexec/postfix
	${CHOWN} root:wheel ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	${CHMOD} 755 ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	-${RM} -f ${WRKSRC}/conf/*.orig

post-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.postfix ${PREFIX}/etc
	${LN} -sf ${PREFIX}/share/postfix/postfix-script /etc/postfix
	${INSTALL_DATA_DIR} ${POSTFIX_SPOOL}
	${CHMOD} 755 ${POSTFIX_SPOOL}
	${TEST} -f /etc/postfix/main.cf || \
		${INSTALL_DATA} ${PREFIX}/share/postfix/main.cf /etc/postfix
	${TEST} -f /etc/postfix/master.cf || \
		${INSTALL_DATA} ${PREFIX}/share/postfix/master.cf /etc/postfix

.include "../../mk/bsd.pkg.mk"
