# $NetBSD: Makefile,v 1.2 1999/05/24 20:39:42 tv Exp $
#

DISTNAME=		xcopilot-0.6.6
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@netbsd.org
HOMEPAGE=		http://xcopilot.cuspy.com/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

NOT_FOR_PLATFORM=	*-*-alpha	# suspected LP64 bugs

GNU_CONFIGURE=		yes
USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
