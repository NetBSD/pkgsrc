# $NetBSD: Makefile,v 1.1 1999/05/29 20:57:17 christos Exp $

DISTNAME=	postfix-19990317-pl05
CATEGORIES=	mail
MASTER_SITES=	ftp://postfix.cloud9.net/official/

MAINTAINER=	christos@netbsd.org
HOMEPAGE=	http://www.postfix.org

MIRROR_DISTFILE= no
#NO_WRKSUBDIR=   yes
#NO_WRKSRC=   yes

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

.include "../../mk/bsd.pkg.mk"
