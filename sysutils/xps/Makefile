# $NetBSD: Makefile,v 1.25 2004/04/18 23:13:00 snj Exp $

DISTNAME=	xps-3.14
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.netwinder.org/users/r/rocky/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.netwinder.org/~rocky/xps-home/
COMMENT=	Displays the Unix process list as a hierarchical tree

GNU_CONFIGURE=	# defined
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_PERL5=	build
USE_X11BASE=	# defined

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
