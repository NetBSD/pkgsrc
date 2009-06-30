# $NetBSD: Makefile,v 1.21 2009/06/30 00:07:11 joerg Exp $
#

DISTNAME=	magic-7.1
PKGREVISION=	5
CATEGORIES=	cad
MASTER_SITES=	http://vlsi.cornell.edu/magic/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://vlsi.cornell.edu/magic/
COMMENT=	Integrated circuit layout system

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake printf
USE_GNU_READLINE=	# uses rl_*_completion_function
MAKE_ENV+=	MAGIC_HOME=${PREFIX:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
CPPFLAGS+=	-DIS_BIG_ENDIAN
.else
CPPFLAGS+=	-DIS_LITTLE_ENDIAN
.endif

USE_TOOLS+=		awk:run
REPLACE_INTERPRETER+=	awk
REPLACE.awk.old=	/bin/awk
REPLACE.awk.new=	${TOOLS_PATH.awk}
REPLACE_FILES.awk=	ext2spice/spice2sim

post-patch:
	cd ${WRKSRC} && for f in `${FIND} . -type f -exec ${GREP} -l CAD_HOME {} /dev/null \\;` ; do \
		${ECHO} "Replacing CAD_HOME in $$f" ; \
		${MV} -f $$f $$f.bak ; ${SED} 's;CAD_HOME;MAGIC_HOME;g' $$f.bak > $$f ; \
		${RM} $$f.bak ; \
		done
	${CHMOD} 755 ${WRKSRC}/scripts/config

do-configure:
	cd ${WRKSRC} && ${PRINTF} '1\n2\n6\n\n\n\n\n\n\n\n\n\n\n' | \
		${SETENV} ${MAKE_ENV} ./scripts/config

.include "../../devel/readline/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
