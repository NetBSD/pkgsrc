# $NetBSD: Makefile,v 1.18.2.1 2002/06/30 06:24:17 jlam Exp $

DISTNAME=	xps-3.14
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.netwinder.org/users/r/rocky/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.netwinder.org/~rocky/xps-home/
COMMENT=	displays the Unix process list as a hierarchical tree

BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

USE_GMAKE=	# defined
USE_X11BASE=	# defined

USE_BUILDLINK2=	# defined
GNU_CONFIGURE=	# defined

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
