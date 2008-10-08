# $NetBSD: Makefile,v 1.1.1.1 2008/10/08 19:53:47 wiz Exp $
#

DISTNAME=	cc65-sources-2.12.0
PKGNAME=	${DISTNAME:S/-sources//}
CATEGORIES=	cross lang
MASTER_SITES=	ftp://ftp.musoftware.de/pub/uz/cc65/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.cc65.org/
COMMENT=	C cross compiler for 6502 target systems

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
MAKE_FILE=	make/gcc.mak
USE_TOOLS+=	gmake perl
REPLACE_PERL=	src/ca65html/ca65html

.include "../../mk/bsd.pkg.mk"
