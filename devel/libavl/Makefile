# $NetBSD: Makefile,v 1.7 2003/07/21 16:43:26 martti Exp $
#

DISTNAME=	avl-1.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=avl/}
#MASTER_SITES=	ftp://ftp.gnu.org/pub/gnu/avl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.msu.edu/user/pfaffben/avl/
COMMENT=	Library for manipulation of balanced binary trees

GNU_CONFIGURE=	YES
USE_NEW_TEXINFO=	YES
INFO_FILES=	avl.info

# This text file documentation is not installed so just touch it
# and makeinfo is not needed at build time.
pre-build:
	${TOUCH} ${WRKSRC}/avl.text

.include "../../mk/bsd.pkg.mk"
