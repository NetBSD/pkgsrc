# $NetBSD: Makefile,v 1.1.1.1 2000/08/14 04:33:24 itojun Exp $

DISTNAME=	postfix-19991231-pl08
PKGNAME=	postfix-19991231pl08
CATEGORIES=	mail
MASTER_SITES=	ftp://postfix.cloud9.net/official/

.include "../../mk/bsd.prefs.mk"

.if defined(POSTFIX_VERP) && ${POSTFIX_VERP} == YES
PATCHFILES=		postfix-19991231-pl06-verp.patch.gz
PATCH_SITES=		ftp://ftp.gw.com/pub/people/kim/patches/
PATCH_DIST_STRIP=	-p1
.endif

MAINTAINER=	christos@netbsd.org
HOMEPAGE=	http://www.postfix.org/

MIRROR_DISTFILE= no
MANCOMPRESSED_IF_MANZ=	yes
DIST_SUBDIR=	postfix

POSTFIX_SPOOL=	/var/spool/postfix

.if defined(POSTFIX_PCRE) && ${POSTFIX_PCRE} == YES
DEPENDS+=	pcre-2.08:../../devel/pcre
CFLAGS+=	-DHAS_PCRE -I${LOCALBASE}/include
AUXLIBS=	-lpcre
MAKE_ENV+=	AUXLIBS="${AUXLIBS}"
.endif

MANINSTALL?=	maninstall catinstall

BUILD_DEFS+=	POSTFIX_PCRE POSTFIX_VERP MANINSTALL

PLIST_SRC=	${PKGDIR}/PLIST
.for i in ${MANINSTALL}
PLIST_SRC+=	${PKGDIR}/PLIST.$i
.endfor

pre-patch:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist

pre-configure:
	${CP} ${WRKSRC}/conf/main.cf ${WRKSRC}/conf/main.cf.dist
	${CP} ${WRKSRC}/util/sys_defs.h ${WRKSRC}/util/sys_defs.h.dist
	${CP} ${WRKSRC}/Makefile.inc ${WRKSRC}/Makefile.inc.dist
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/conf/main.cf.dist \
	    > ${WRKSRC}/conf/main.cf
	${SED} -e 's:__PREFIX:'${PREFIX}':g' \
	    < ${WRKSRC}/util/sys_defs.h.dist \
	    > ${WRKSRC}/util/sys_defs.h
	capitalopsys=`${ECHO} ${OPSYS} | ${TR} a-z A-Z`; \
	osmajorversion=`${ECHO} ${OS_VERSION} | ${SED} -e 's/\..*//g'`; \
	${SED} -e 's:@OPSYS@:'$$capitalopsys$$osmajorversion':g' \
	    < ${WRKSRC}/Makefile.inc.dist \
	    > ${WRKSRC}/Makefile.inc

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.postfix

pre-install:
	${MKDIR} /etc/postfix ${PREFIX}/share/postfix \
	  ${PREFIX}/share/doc/postfix ${PREFIX}/libexec/postfix
	${CHOWN} root:wheel ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	${CHMOD} 755 ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix

post-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.postfix ${PREFIX}/etc
	${LN} -sf ${PREFIX}/share/postfix/postfix-script /etc/postfix
	-${MKDIR} ${POSTFIX_SPOOL}
	$(CHMOD) 755 ${POSTFIX_SPOOL}
	${TEST} -f /etc/postfix/main.cf || ${INSTALL_DATA} ${PREFIX}/share/postfix/main.cf /etc/postfix
	${TEST} -f /etc/postfix/master.cf || ${INSTALL_DATA} ${PREFIX}/share/postfix/master.cf /etc/postfix

.include "../../mk/bsd.pkg.mk"
