# $NetBSD: Makefile,v 1.1.1.1 2002/07/26 09:10:06 grant Exp $
#

DISTNAME=		skey-1.1.5
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Port of OpenBSD s/key implementation

BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"

