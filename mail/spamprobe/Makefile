# $NetBSD: Makefile,v 1.2 2003/06/02 01:18:37 jschauma Exp $

DISTNAME=	spamprobe-0.8b
COMMENT=	Spam detector using Bayesian analysis of word counts
CATEGORIES=	mail
MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://spamprobe.sourceforge.net/
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --with-db=${BUILDLINK_PREFIX.db4}/include/db4

.include "../../databases/db4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
