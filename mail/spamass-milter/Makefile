# $NetBSD: Makefile,v 1.14 2005/03/14 14:21:06 wiz Exp $
#

DISTNAME=	spamass-milter-0.2.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/spamass-milt/

MAINTAINER=	tech-pkg@NetBSD.org
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
