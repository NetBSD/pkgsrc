# $NetBSD: Makefile,v 1.6.2.1 2004/01/29 18:48:36 agc Exp $
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
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

post-install:
	${RANLIB} ${PREFIX}/lib/libskey.a

.include "../../mk/bsd.pkg.mk"
