# $NetBSD: Makefile,v 1.5 2019/12/17 16:01:28 rillig Exp $
#

DISTNAME=	make-env-phases-19.3
CATEGORIES=	regress
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tests whether MAKE_ENV changes between build and install phase

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}
USE_TOOLS=	diff grep printf

# XXX: Why do these differ between do-build and do-install?
#
# In do-install, the -I/usr/include is not there in CFLAGS and CPPFLAGS.
#
# In do-install, the -L and -Wl,-R options for /usr/lib and $PREFIX/lib
# are not there.
#
MAY_DIFFER_VARS=	CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
MAY_DIFFER_GREP_ARGS=	${MAY_DIFFER_VARS:@var@-e \^${var:Q}@}

do-build:
	${RUN} cd ${WRKDIR} \
	&& printf '%s\n' ${MAKE_ENV} \
	   | grep -v ${MAY_DIFFER_GREP_ARGS} >build-make-env.txt

do-install:
	${RUN} cd ${WRKDIR} \
	&& printf '%s\n' ${MAKE_ENV} \
	   | grep -v ${MAY_DIFFER_GREP_ARGS} >install-make-env.txt \
	&& diff -u build-make-env.txt install-make-env.txt \
	&& echo "The variable MAKE_ENV remains unchanged (ignoring ${MAY_DIFFER_VARS})." \

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
