# $NetBSD: Makefile,v 1.11 2003/07/17 22:52:49 grant Exp $
#

DISTNAME=       aide-0.9
CATEGORIES=	security
MASTER_SITES=   http://www.cs.tut.fi/~rammer/ \
		ftp://ftp.cs.tut.fi/pub/src/gnu/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	free intrusion detection system for checking file integrity

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
BUILDLINK_DEPENDS.mhash?=	mhash>=0.8.17

USE_BUILDLINK2= # defined

GNU_CONFIGURE=	yes
#don't set YACC so configure can correctly find bison
YACC=

.include "../../security/mhash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
