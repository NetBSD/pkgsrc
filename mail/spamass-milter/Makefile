# $NetBSD: Makefile,v 1.11 2004/11/22 21:22:11 wiz Exp $
#

DISTNAME=	spamass-milter-0.1.3a
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/spamass-milt/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/spamass-milt/
COMMENT=	Milter interface to Spamassassin

DEPENDS+=	spamassassin>=2.44:../../mail/spamassassin

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_PKGINSTALL=	YES
USE_LANGUAGES=	c++

RCD_SCRIPTS=	spamass-milter

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
