# $NetBSD: Makefile,v 1.8 2013/06/26 12:09:26 ryoon Exp $
#

DISTNAME=	avl-1.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=avl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://adtinfo.org/
COMMENT=	Library for manipulation of balanced binary trees
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
INFO_FILES=	yes

# The text and html files documentation are not installed so just touch
# them and makeinfo and texi2html are not needed at build time.
pre-build:
	${TOUCH} ${WRKSRC}/avl.text ${WRKSRC}/avl.html

.include "../../mk/bsd.pkg.mk"
