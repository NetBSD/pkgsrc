# $NetBSD: Makefile,v 1.11 2005/05/22 20:08:31 jlam Exp $
#

DISTNAME=		skey-1.1.5
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Port of OpenBSD s/key implementation

USE_PERL5=		build
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	bin include lib man/man1 man/man8

post-install:
	${RANLIB} ${PREFIX}/lib/libskey.a

.include "../../mk/bsd.pkg.mk"
