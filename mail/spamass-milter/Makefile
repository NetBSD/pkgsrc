# $NetBSD: Makefile,v 1.1.1.1 2003/04/03 14:46:02 manu Exp $
#

DISTNAME=	spamass-milter-0.1.3a
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/spamass-milt/

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://savannah.nongnu.org/projects/spamass-milt/
COMMENT=	Milter interface to Spamassassin

DEPENDS+=	spamassassin:../../mail/spamassassin

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../mk/pthread.buildlink2.mk"
.include "../../mail/libmilter/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
