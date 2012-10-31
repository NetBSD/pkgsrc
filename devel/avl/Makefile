# $NetBSD: Makefile,v 1.6 2012/10/31 11:16:39 asau Exp $
#

DISTNAME=	avl-1.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=avl/}
#MASTER_SITES=	ftp://ftp.gnu.org/pub/gnu/avl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stanford.edu/~blp/avl/
COMMENT=	Library for manipulation of balanced binary trees

GNU_CONFIGURE=	YES
INFO_FILES=	# PLIST

# The text and html files documentation are not installed so just touch
# them and makeinfo and texi2html are not needed at build time.
pre-build:
	${TOUCH} ${WRKSRC}/avl.text ${WRKSRC}/avl.html

.include "../../mk/bsd.pkg.mk"
