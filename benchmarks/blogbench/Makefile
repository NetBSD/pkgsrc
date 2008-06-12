# $NetBSD: Makefile,v 1.5 2008/06/12 02:14:15 joerg Exp $
#

DISTNAME=	blogbench-1.0
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.blogbench.pureftpd.org/blogbench/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blogbench.pureftpd.org/
COMMENT=	Portable filesystem benchmark

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
