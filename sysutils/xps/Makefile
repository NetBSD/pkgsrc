# $NetBSD: Makefile,v 1.15 2001/08/29 22:41:21 jlam Exp $

DISTNAME=	xps-3.14
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.netwinder.org/users/r/rocky/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.netwinder.org/~rocky/xps-home/
COMMENT=	displays the Unix process list as a hierarchical tree

BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

USE_GMAKE=	# defined
USE_X11BASE=	# defined

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		XINCLUDES="-I${BUILDLINK_X11_DIR}/include"

.include "../../x11/lesstif/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
