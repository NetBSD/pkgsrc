# $NetBSD: Makefile,v 1.1.1.1 1998/08/24 04:45:50 thorpej Exp $

DISTNAME=		cqcam-0.45a
CATEGORIES=     	graphics x11
MASTER_SITES=		http://www.cs.virginia.edu/~patrick/cqcam/
EXTRACT_SUFX=		.tgz

# XXX uses inb/outb
ONLY_FOR_ARCHS=		i386

MAINTAINER=	packages@netbsd.org

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	tk-8.0p2:../../x11/tk80

LICENSE=	no-profit

MAN1=		cqcam.1

.include "../../mk/bsd.pkg.mk"
