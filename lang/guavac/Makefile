# $NetBSD: Makefile,v 1.16 2004/05/31 16:43:46 kristerw Exp $
#

DISTNAME=	guavac-1.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/devel/compilers/guavac/ \
		ftp://ftp.Germany.EU.net/pub/programming/languages/java/guavac/ \
		ftp://sunsite.mff.cuni.cz/Languages/Java/guavac/ \
		ftp://sunsite.auc.dk/pub/languages/java/guavac/

MAINTAINER=	tech-pkg@NetBSD.org
# HOMEPAGE=	http://www.cs.berkeley.edu/~engberg/guavac/ no longer exists
COMMENT=	Free compiler for the Java language

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=  yes

post-install:
	${MV} ${PREFIX}/man/cat1/guavac.man ${PREFIX}/man/cat1/guavac.0

.include "../../mk/bsd.pkg.mk"

# next check has to be below include, else ${GREP} and ${ECHO} don't get
# expanded correctly

HAVE_GCC27!=	${CXX} -v 2>&1 | ${GREP} '2\.7\.'; ${ECHO}
.if !empty(HAVE_GCC27)
PKG_FAIL_REASON= "${PKGNAME} requires gcc 2.8 or egcs or better for ANSI C++"
.endif
