# $NetBSD: Makefile,v 1.5 2004/07/30 15:50:38 minskim Exp $

DISTNAME=	postal-0.62
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/postal/
EXTRACT_SUFX=	.tgz

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.coker.com.au/postal/
COMMENT=	Tool for benchmarking SMTP/POP servers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
