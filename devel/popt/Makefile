# $NetBSD: Makefile,v 1.2 2000/11/19 14:57:54 wiz Exp $
#

DISTNAME=	popt-1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.redhat.com/redhat/code/popt/

MAINTAINER=	packages@netbsd.org

CONFLICTS=	ORBit<=0.5.3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAKE_ENV+=	LOCALEDIR=${LOCAL_BASE}/share/locale/

.include "../../mk/bsd.pkg.mk"
