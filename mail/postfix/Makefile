# $NetBSD: Makefile,v 1.8 1999/06/26 16:55:27 christos Exp $

DISTNAME=	postfix-19990317-pl05
PKGNAME=	postfix-19990317p05
CATEGORIES=	mail
MASTER_SITES=	ftp://postfix.cloud9.net/official/

MAINTAINER=	christos@netbsd.org
HOMEPAGE=	http://www.postfix.org/

MIRROR_DISTFILE= no

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
	${SED} -e 's:@OPSYS@:'${CAPITAL_OPSYS}${OS_MAJOR_VERSION}':g' \
	    < ${WRKSRC}/Makefile.inc.dist \
	    > ${WRKSRC}/Makefile.inc

post-build:
	${SED} -e 's#@@PREFIX@@#${PREFIX}#g' \
	  <${FILESDIR}/mailer.conf >${WRKDIR}/mailer.conf.postfix

pre-install:
	${MKDIR} /etc/postfix ${PREFIX}/share/postfix \
	  ${PREFIX}/share/doc/postfix ${PREFIX}/libexec/postfix
	chown root:wheel ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	chmod 755 ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix

post-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.postfix ${PREFIX}/etc

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=  yes
.endif

.include "../../mk/bsd.pkg.mk"
