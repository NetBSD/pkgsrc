# $NetBSD: Makefile,v 1.10 1999/08/24 12:51:24 agc Exp $

DISTNAME=	bison-1.28
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=bison/}

MAINTAINER=	thorpej@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/bison/bison.html

GNU_CONFIGURE=	yes
# needed for $TMPDIR parsing
CFLAGS+=	-Dunix

INFO_FILES=	bison.info

.include "../../mk/bsd.pkg.mk"
