# $NetBSD: Makefile,v 1.8 2001/07/01 11:46:49 tron Exp $
#

DISTNAME=	popt-1.5.-1
PKGNAME=	popt-1.5
CATEGORIES=	devel
MASTER_SITES=	ftp://people.redhat.com/sopwith/popt/

MAINTAINER=	packages@netbsd.org
COMMENT=	Command line option parsing library

BUILD_USES_MSGFMT=	yes

CONFLICTS=	ORBit<=0.5.3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}
MAKE_ENV+=	LOCALEDIR=${LOCAL_BASE}/share/locale/

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
