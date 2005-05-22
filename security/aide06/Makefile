# $NetBSD: Makefile,v 1.10 2005/05/22 19:11:12 jlam Exp $
#

DISTNAME=       aide-0.6
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Older intrusion detection system for checking file integrity

#BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	yacc lex
USE_TOOLS+=	bison

.include "../../mk/bsd.pkg.mk"
