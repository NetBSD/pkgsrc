# $NetBSD: Makefile,v 1.22 2006/02/05 23:09:58 joerg Exp $
#

DISTNAME=	spamass-milter-0.3.0
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/spamass-milt/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/spamass-milt/
COMMENT=	Milter interface to Spamassassin

DEPENDS+=	spamassassin>=2.44:../../mail/spamassassin

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c++

RCD_SCRIPTS=	spamass-milter

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
