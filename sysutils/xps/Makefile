# $NetBSD: Makefile,v 1.19 2002/07/24 19:45:28 jlam Exp $

DISTNAME=	xps-3.14
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.netwinder.org/users/r/rocky/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.netwinder.org/~rocky/xps-home/
COMMENT=	displays the Unix process list as a hierarchical tree

USE_PERL5=	build
USE_GMAKE=	# defined
USE_X11BASE=	# defined

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		XINCLUDES="-I${BUILDLINK_X11_DIR}/include"

.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
