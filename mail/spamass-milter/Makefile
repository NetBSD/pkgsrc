# $NetBSD: Makefile,v 1.3 2003/05/02 11:55:41 wiz Exp $
#

DISTNAME=	spamass-milter-0.1.3a
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/spamass-milt/

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://savannah.nongnu.org/projects/spamass-milt/
COMMENT=	Milter interface to Spamassassin

DEPENDS+=	spamassassin>=2.44:../../mail/spamassassin

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
