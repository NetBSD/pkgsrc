# $NetBSD: Makefile,v 1.7 2004/03/26 02:27:44 wiz Exp $
#

DISTNAME=	spamass-milter-0.1.3a
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/spamass-milt/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/spamass-milt/
COMMENT=	Milter interface to Spamassassin

DEPENDS+=	spamassassin>=2.44:../../mail/spamassassin

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES
USE_GCC_SHLIB=	YES

RCD_SCRIPTS=	spamass-milter

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
