# $NetBSD: Makefile,v 1.4 1999/05/30 11:52:39 tron Exp $

DISTNAME=	postfix-19990317-pl05
PKGNAME=	postfix-19990317p05
CATEGORIES=	mail
MASTER_SITES=	ftp://postfix.cloud9.net/official/

MAINTAINER=	christos@netbsd.org
HOMEPAGE=	http://www.postfix.org

MIRROR_DISTFILE= no

pre-patch:
	${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist

pre-configure:
	${CP} ${WRKSRC}/conf/main.cf ${WRKSRC}/conf/main.cf.dist
	${CP} ${WRKSRC}/util/sys_defs.h ${WRKSRC}/util/sys_defs.h.dist
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/conf/main.cf.dist \
	    > ${WRKSRC}/conf/main.cf
	${SED} -e 's:__PREFIX:'${PREFIX}':g'< ${WRKSRC}/util/sys_defs.h.dist \
	    > ${WRKSRC}/util/sys_defs.h

pre-install:
	${MKDIR} ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	chown root.wheel ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix
	chmod 755 ${PREFIX}/share/postfix ${PREFIX}/libexec/postfix

.include "../../mk/bsd.prefs.mk"

.ifdef MANZ
MANCOMPRESSED=  yes
.endif

.include "../../mk/bsd.pkg.mk"
