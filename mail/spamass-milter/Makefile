# $NetBSD: Makefile,v 1.5 2003/09/11 18:22:40 jmmv Exp $
#

DISTNAME=	spamass-milter-0.1.3a
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/spamass-milt/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/spamass-milt/
COMMENT=	Milter interface to Spamassassin

DEPENDS+=	spamassassin>=2.44:../../mail/spamassassin

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES

RCD_SCRIPTS=	spamass-milter

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
