# $NetBSD: Makefile,v 1.2 1998/08/24 11:45:17 frueauf Exp $
#

DISTNAME=	cqcam-0.45a
CATEGORIES=    	graphics x11
MASTER_SITES=	http://www.cs.virginia.edu/~patrick/cqcam/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cs.virginia.edu/~patrick/cqcam/

# XXX uses inb/outb
ONLY_FOR_ARCHS=	i386

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	tk-8.0p2:../../x11/tk80

LICENSE=	no-profit

.include "../../mk/bsd.pkg.mk"
