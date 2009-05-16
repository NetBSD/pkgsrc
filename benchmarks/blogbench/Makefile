# $NetBSD: Makefile,v 1.6 2009/05/16 21:30:37 zafer Exp $
#

DISTNAME=	blogbench-1.0
PKGREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.uvsq.fr/pub/networking/ftp/pure-ftpd/misc/blogbench/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://blogbench.pureftpd.org/
COMMENT=	Portable filesystem benchmark

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
