# $NetBSD: Makefile,v 1.18 2005/05/15 19:05:54 jlam Exp $
#

DISTNAME=       aide-0.10
CATEGORIES=	security
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=aide/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Free intrusion detection system for checking file integrity

BUILDLINK_DEPENDS.mhash?=	mhash>=0.8.17


GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	lex make yacc
USE_TOOLS+=	bison

.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if empty(_USE_NEW_TOOLS:M[yY][eE][sS])
#don't set YACC so configure can correctly find bison
YACC=
.endif
