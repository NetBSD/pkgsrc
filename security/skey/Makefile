# $NetBSD: Makefile,v 1.2 2002/08/28 03:10:04 jlam Exp $
#

DISTNAME=		skey-1.1.5
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Port of OpenBSD s/key implementation

ONLY_FOR_PLATFORM=	Darwin-*-* SunOS-*-*	# in NetBSD base system

USE_PERL5=		build
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"

