# $NetBSD: Makefile,v 1.4 2001/02/16 14:38:57 wiz Exp $
#

DISTNAME=	popt-1.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.redhat.com/redhat/code/popt/

MAINTAINER=	packages@netbsd.org
COMMENT=	Command line option parsing library

BUILD_DEPENDS+=	xgettext:../../devel/gettext

CONFLICTS=	ORBit<=0.5.3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAKE_ENV+=	LOCALEDIR=${LOCAL_BASE}/share/locale/

.include "../../mk/bsd.pkg.mk"
