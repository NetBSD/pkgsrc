# $NetBSD: Makefile,v 1.29 2010/06/05 13:45:12 gdt Exp $
#

DISTNAME=	spamass-milter-0.3.1
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/spamass-milt/

PATCHFILES=	spamass-milter-001.patch


MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/spamass-milt/
COMMENT=	Milter interface to Spamassassin

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	spamassassin>=2.44:../../mail/spamassassin

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

RCD_SCRIPTS=	spamass-milter

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
