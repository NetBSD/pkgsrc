# $NetBSD: Makefile,v 1.3 2000/08/23 23:14:24 tron Exp $
#

DISTNAME=		xcopilot-0.6.6
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@netbsd.org
HOMEPAGE=		http://xcopilot.cuspy.com/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

NOT_FOR_PLATFORM=	*-*-alpha	# suspected LP64 bugs

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_XPM=		YES

.include "../../mk/bsd.pkg.mk"
