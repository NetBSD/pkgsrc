# $NetBSD: Makefile,v 1.4 2005/07/13 17:51:50 drochner Exp $
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
