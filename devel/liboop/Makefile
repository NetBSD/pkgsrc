# $NetBSD: Makefile,v 1.2 2004/02/14 17:21:38 jlam Exp $
#

DISTNAME=		liboop-0.9
CATEGORIES=		devel
MASTER_SITES=		http://download.ofb.net/liboop/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.liboop.org/
COMMENT=		Event loop management library

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
