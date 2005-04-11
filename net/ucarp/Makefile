# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:01 tv Exp $
#

DISTNAME=		ucarp-1.0
PKGREVISION=	1
CATEGORIES=		net
MASTER_SITES=		http://www.pureftpd.org/ucarp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ucarp.org/
COMMENT=		Common Address Redundancy Protocol (CARP) for Unix

GNU_CONFIGURE=		yes

USE_BUILTIN.libpcap=	no

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
