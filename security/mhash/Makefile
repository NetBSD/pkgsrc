# $NetBSD: Makefile,v 1.14 2005/03/25 09:31:50 adam Exp $

DISTNAME=	mhash-0.9.2
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mhash/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mhash.sourceforge.net/
COMMENT=	Hash algorithms library

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PERL5=		build
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
