# $NetBSD: Makefile,v 1.1 2010/02/15 13:35:21 obache Exp $
#

.include "version.mk"

DISTNAME=	sj3-${SJ3_VERSION}
CATEGORIES=	japanese inputmethod
MASTER_SITES=	http://sj3.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/sj3/
COMMENT=	SJ3 Japanese input method

META_PACKAGE=	yes

DEPENDS+=	sj3-server>=${SJ3_VERSION}:../../wip/sj3-server
DEPENDS+=	sj3-client>=${SJ3_VERSION}:../../wip/sj3-client

.include "../../mk/bsd.pkg.mk"
