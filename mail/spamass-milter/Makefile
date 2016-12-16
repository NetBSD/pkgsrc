# $NetBSD: Makefile,v 1.35 2016/12/16 15:56:05 hans Exp $
#

DISTNAME=	spamass-milter-0.4.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/spamass-milt/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/spamass-milt/
COMMENT=	Milter interface to Spamassassin

LICENSE=	original-bsd

DEPENDS+=	spamassassin>=2.44:../../mail/spamassassin

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

CPPFLAGS.SunOS+=	-Du_int8_t=uint8_t

RCD_SCRIPTS=	spamass-milter
SMF_METHODS=	spamass-milter

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
