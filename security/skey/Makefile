# $NetBSD: Makefile,v 1.3 2003/06/02 01:17:04 jschauma Exp $
#

DISTNAME=		skey-1.1.5
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Port of OpenBSD s/key implementation

ONLY_FOR_PLATFORM=	Darwin-*-* SunOS-*-*	# in NetBSD base system

USE_PERL5=		build
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"

