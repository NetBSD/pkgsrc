# $NetBSD: Makefile,v 1.6 2004/04/06 14:01:51 tv Exp $
#

DISTNAME=	milter-greylist-1.0.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@netbsd.rg
HOMEPAGE=	http://hcpnet.free.fr/milter-greylist/
COMMENT=	Easy-to-use greylist milter for sendmail

USE_PKGINSTALL=	YES
USE_BUILDLINK2= YES

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-user=smmsp --prefix=${PREFIX}
ALL_TARGET=	milter-greylist

PKG_GROUPS=	smmsp
PKG_USERS=	smmsp:smmsp::Sendmail\\ Message\\ Submission\\ Program

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
