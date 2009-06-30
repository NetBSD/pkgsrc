# $NetBSD: Makefile,v 1.3 2009/06/30 00:07:12 joerg Exp $
#

DISTNAME=	cc65-sources-2.12.0
PKGNAME=	${DISTNAME:S/-sources//}
CATEGORIES=	cross lang
MASTER_SITES=	ftp://ftp.musoftware.de/pub/uz/cc65/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cc65.org/
COMMENT=	C cross compiler for 6502 target systems

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
MAKE_FILE=	make/gcc.mak
USE_TOOLS+=	gmake perl
REPLACE_PERL=	src/ca65html/ca65html

.include "../../mk/bsd.pkg.mk"
