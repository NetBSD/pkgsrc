# $NetBSD: Makefile,v 1.5 2003/07/23 16:03:55 salo Exp $
#

DISTNAME=		skey-1.1.5
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Port of OpenBSD s/key implementation

NOT_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-* # in base system

USE_PERL5=		build
USE_BUIDLINK2=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
