# $NetBSD: Makefile,v 1.1.1.1 2004/07/08 10:30:31 xtraeme Exp $
#

DISTNAME=		ucarp-1.0
CATEGORIES=		net
MASTER_SITES=		http://www.pureftpd.org/ucarp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ucarp.org/
COMMENT=		Common Address Redundancy Protocol (CARP) for Unix

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

USE_BUILTIN.libpcap=	no

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
