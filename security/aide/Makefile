# $NetBSD: Makefile,v 1.15 2004/10/03 00:18:07 tv Exp $
#

DISTNAME=       aide-0.9
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=   http://www.cs.tut.fi/~rammer/ \
		ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Free intrusion detection system for checking file integrity

BUILDLINK_DEPENDS.mhash?=	mhash>=0.8.17

USE_BUILDLINK3= yes

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	lex yacc

.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
#don't set YACC so configure can correctly find bison
YACC=
