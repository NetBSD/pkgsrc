# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/06/23 18:40:13 jlam Exp $
#

DISTNAME=	magic-7.1
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://vlsi.cornell.edu/magic/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://vlsi.cornell.edu/magic/
COMMENT=	Integrated circuit layout system

USE_GMAKE=	yes
MAKE_ENV+=	MAGIC_HOME=${PREFIX}

post-patch:
	cd ${WRKSRC} && for f in `${FIND} . -type f -exec ${GREP} -l CAD_HOME {} /dev/null \;` ; do \
		${ECHO} "Replacing CAD_HOME in $$f" ; \
		${MV} -f $$f $$f.bak ; ${SED} 's;CAD_HOME;MAGIC_HOME;g' $$f.bak > $$f ; \
		${RM} $$f.bak ; \
		done
	${CHMOD} 755 ${WRKSRC}/scripts/config

do-configure:
	cd ${WRKSRC} && printf "1\n2\n6\n\n\n\n\n\n\n\n\n\n\n" | \
		${ENV} ${MAKE_ENV} ./scripts/config

.include "../../mk/bsd.pkg.mk"
