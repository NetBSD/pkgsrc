# $NetBSD: Makefile,v 1.1.1.1 2005/02/14 22:05:53 xtraeme Exp $
#

DISTNAME=	blogbench-1.0
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.blogbench.pureftpd.org/blogbench/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://blogbench.pureftpd.org/
COMMENT=	Portable filesystem benchmark

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
