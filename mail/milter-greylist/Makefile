# $NetBSD: Makefile,v 1.1.1.1 2004/03/04 14:47:56 manu Exp $
#

DISTNAME=	milter-greylist-0.9
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@netbsd.rg
COMMENT=	Greylist milter for sendmail

USE_PKGINSTALL=	YES
USE_BUILDLINK2= YES

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-user=smmsp --prefix=${PREFIX}

PKG_GROUPS=	smmsp
PKG_USERS=	smmsp:smmsp::Sendmail\\ Message\\ Submission\\ Program

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
