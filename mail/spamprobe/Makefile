# $NetBSD: Makefile,v 1.5 2003/12/01 12:16:14 grant Exp $

DISTNAME=	spamprobe-0.8b
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --with-db=${BUILDLINK_PREFIX.db4}/include/db4

.include "../../databases/db4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
