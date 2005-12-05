# $NetBSD: Makefile,v 1.14 2005/12/05 23:55:18 rillig Exp $
#

DISTNAME=		skey-1.1.5
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Port of OpenBSD s/key implementation

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONF_FILES+=		${PREFIX}/share/examples/skey/skeykeys \
			${PKG_SYSCONFDIR}/skeykeys

INSTALLATION_DIRS=	bin include lib man/man1 man/man8

post-install:
	${RANLIB} ${PREFIX}/lib/libskey.a

.include "../../mk/bsd.pkg.mk"
