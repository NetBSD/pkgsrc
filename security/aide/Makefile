# $NetBSD: Makefile,v 1.16 2004/12/01 16:42:53 wiz Exp $
#

DISTNAME=       aide-0.10
CATEGORIES=	security
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=aide/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Free intrusion detection system for checking file integrity

BUILDLINK_DEPENDS.mhash?=	mhash>=0.8.17

USE_BUILDLINK3= yes

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	lex make yacc

.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
#don't set YACC so configure can correctly find bison
YACC=
