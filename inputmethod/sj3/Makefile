# $NetBSD: Makefile,v 1.3 2015/03/15 17:56:16 hiramatsu Exp $
#

.include "version.mk"

DISTNAME=	sj3-${SJ3_VERSION}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://sj3.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sj3/
COMMENT=	SJ3 Japanese input method

META_PACKAGE=	yes

DEPENDS+=	sj3-server>=${SJ3_VERSION}:../../inputmethod/sj3-server
DEPENDS+=	sj3-client>=${SJ3_VERSION}:../../inputmethod/sj3-client

.include "../../mk/bsd.pkg.mk"
