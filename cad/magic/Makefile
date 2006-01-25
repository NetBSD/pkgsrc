# $NetBSD: Makefile,v 1.14 2006/01/25 22:21:09 joerg Exp $
#

DISTNAME=	magic-7.1
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://vlsi.cornell.edu/magic/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://vlsi.cornell.edu/magic/
COMMENT=	Integrated circuit layout system

USE_TOOLS+=	gmake
USE_GNU_READLINE=	# uses rl_*_completion_function
MAKE_ENV+=	MAGIC_HOME=${PREFIX:Q}

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
CPPFLAGS+=	-DIS_BIG_ENDIAN
.else
CPPFLAGS+=	-DIS_LITTLE_ENDIAN
.endif

.include "../../mk/x11.buildlink3.mk"

post-patch:
	cd ${WRKSRC} && for f in `${FIND} . -type f -exec ${GREP} -l CAD_HOME {} /dev/null \;` ; do \
		${ECHO} "Replacing CAD_HOME in $$f" ; \
		${MV} -f $$f $$f.bak ; ${SED} 's;CAD_HOME;MAGIC_HOME;g' $$f.bak > $$f ; \
		${RM} $$f.bak ; \
		done
	${CHMOD} 755 ${WRKSRC}/scripts/config

do-configure:
	cd ${WRKSRC} && printf "1\n2\n6\n\n\n\n\n\n\n\n\n\n\n" | \
		${SETENV} ${MAKE_ENV} ./scripts/config

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
