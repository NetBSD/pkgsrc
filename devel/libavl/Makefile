# $NetBSD: Makefile,v 1.9 2004/02/16 10:30:29 seb Exp $
#

DISTNAME=	avl-1.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=avl/}
#MASTER_SITES=	ftp://ftp.gnu.org/pub/gnu/avl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.msu.edu/user/pfaffben/avl/
COMMENT=	Library for manipulation of balanced binary trees

GNU_CONFIGURE=	YES
INFO_FILES=	avl.info

# The text and html files documentation are not installed so just touch
# them and makeinfo and texi2html are not needed at build time.
pre-build:
	${TOUCH} ${WRKSRC}/avl.text ${WRKSRC}/avl.html

.include "../../mk/bsd.pkg.mk"
