# $NetBSD: Makefile,v 1.6 2000/10/15 14:10:19 itojun Exp $

DISTNAME=	snapshot-20001005
PKGNAME=	postfix-20001005
CATEGORIES=	mail
MASTER_SITES=	ftp://postfix.cloud9.net/experimental/

PATCHFILES=	postfix-20001005snap-v6-20001011a.diff.gz
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCH_DIST_STRIP+=	-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.postfix.org/

DIST_SUBDIR=	postfix

POSTFIX_SPOOL=	/var/spool/postfix

.include "../../mk/bsd.prefs.mk"
# automagically determines IPv6 support
BUILD_DEFS+=	USE_INET6

.if defined(POSTFIX_PCRE) && ${POSTFIX_PCRE} == YES
DEPENDS+=	pcre-2.08:../../devel/pcre
CFLAGS+=	-DHAS_PCRE -I${LOCALBASE}/include
AUXLIBS=	-lpcre
MAKE_ENV+=	AUXLIBS="${AUXLIBS}"
.endif

BUILD_DEFS+=	POSTFIX_PCRE POSTFIX_VERP MANINSTALL

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
	${MKDIR} /etc/postfix ${PREFIX}/share/postfix \
	    ${PREFIX}/share/doc/postfix ${PREFIX}/libexec/postfix
	${CHOWN} root:wheel ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	${CHMOD} 755 ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	${RM} ${WRKSRC}/conf/*.orig

post-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.postfix ${PREFIX}/etc
	${LN} -sf ${PREFIX}/share/postfix/postfix-script /etc/postfix
	-${MKDIR} ${POSTFIX_SPOOL}
	${CHMOD} 755 ${POSTFIX_SPOOL}
	${TEST} -f /etc/postfix/main.cf || \
		${INSTALL_DATA} ${PREFIX}/share/postfix/main.cf /etc/postfix
	${TEST} -f /etc/postfix/master.cf || \
		${INSTALL_DATA} ${PREFIX}/share/postfix/master.cf /etc/postfix

.include "../../mk/bsd.pkg.mk"
