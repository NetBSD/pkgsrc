# $NetBSD: Makefile,v 1.12 2001/02/17 09:07:11 agc Exp $
#

DISTNAME=	guavac-1.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/devel/compilers/guavac/ \
		ftp://ftp.Germany.EU.net/pub/programming/languages/java/guavac/ \
		ftp://sunsite.mff.cuni.cz/Languages/Java/guavac/ \
		ftp://sunsite.auc.dk/pub/languages/java/guavac/

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	http://www.cs.berkeley.edu/~engberg/guavac/ no longer exists
COMMENT=	Free compiler for the Java language

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	egcs-1.1.2:../../lang/egcs
MAKE_ENV+=	PATH=${LOCALBASE}/egcs/bin:$PATH
CXX=		${LOCALBASE}/egcs/bin/gcc
CONFIGURE_ENV+=	CXX=${CXX}
.endif

GNU_CONFIGURE=  yes

post-install:
	${MV} ${PREFIX}/man/cat1/guavac.man ${PREFIX}/man/cat1/guavac.0

.include "../../mk/bsd.pkg.mk"

# next check has to be below include, else ${GREP} and ${ECHO} don't get
# expanded correctly

HAVE_GCC27!=	${CXX} -v 2>&1 | ${GREP} '2\.7\.'; ${ECHO}
.if !empty(HAVE_GCC27)
IGNORE=		"${PKGNAME} requires gcc 2.8 or egcs or better for ANSI C++"
.endif
