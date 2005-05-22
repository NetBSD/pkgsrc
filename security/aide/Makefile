# $NetBSD: Makefile,v 1.19 2005/05/22 19:11:12 jlam Exp $
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
