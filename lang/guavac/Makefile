# $NetBSD: Makefile,v 1.7 1999/01/09 18:39:25 tv Exp $
#

DISTNAME=	guavac-1.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.yggdrasil.com/pub/dist/devel/compilers/guavac/ \
		ftp://ftp.Germany.EU.net/pub/programming/languages/java/guavac/ \
		ftp://sunsite.mff.cuni.cz/Languages/Java/guavac/ \
		ftp://sunsite.auc.dk/pub/languages/java/guavac/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	# http://www.cs.berkeley.edu/~engberg/guavac/ no longer exists

HAVE_GCC27!=	${CXX} -v 2>&1 | grep '2\.7\.'; echo
.if !empty(HAVE_GCC27)
IGNORE=		"requires gcc 2.8 or egcs or better for ANSI C++"
.endif

GNU_CONFIGURE=  yes

post-install:
	${MV} ${PREFIX}/man/cat1/guavac.man ${PREFIX}/man/cat1/guavac.0

.include "../../mk/bsd.pkg.mk"
