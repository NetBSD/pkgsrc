# $NetBSD: Makefile,v 1.9 1999/04/07 13:21:00 agc Exp $
#

DISTNAME=	guavac-1.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/devel/compilers/guavac/ \
		ftp://ftp.Germany.EU.net/pub/programming/languages/java/guavac/ \
		ftp://sunsite.mff.cuni.cz/Languages/Java/guavac/ \
		ftp://sunsite.auc.dk/pub/languages/java/guavac/

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	http://www.cs.berkeley.edu/~engberg/guavac/ no longer exists

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	egcs-1.1.2:../../lang/egcs
MAKE_ENV+=	PATH=${LOCALBASE}/egcs/bin:$PATH
CXX=		${LOCALBASE}/egcs/bin/gcc
CONFIGURE_ENV+=	CXX=${CXX}
.endif

HAVE_GCC27!=	${CXX} -v 2>&1 | grep '2\.7\.'; echo
.if !empty(HAVE_GCC27)
IGNORE=		"requires gcc 2.8 or egcs or better for ANSI C++"
.endif

GNU_CONFIGURE=  yes

post-install:
	${MV} ${PREFIX}/man/cat1/guavac.man ${PREFIX}/man/cat1/guavac.0

.include "../../mk/bsd.pkg.mk"
