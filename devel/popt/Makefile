# $NetBSD: Makefile,v 1.5 2001/03/27 03:19:53 hubertf Exp $
#

DISTNAME=	popt-1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.redhat.com/redhat/code/popt/

MAINTAINER=	packages@netbsd.org
COMMENT=	Command line option parsing library

BUILD_USES_MSGFMT=	yes

CONFLICTS=	ORBit<=0.5.3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAKE_ENV+=	LOCALEDIR=${LOCAL_BASE}/share/locale/

.include "../../mk/bsd.pkg.mk"
