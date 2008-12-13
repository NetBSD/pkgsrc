# $NetBSD: Makefile,v 1.22 2008/12/13 13:58:31 obache Exp $
#

DISTNAME=		skey-1.1.5
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		http://www.sparc.spb.su/solaris/skey/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Port of OpenBSD s/key implementation

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONF_FILES+=		${PREFIX}/share/examples/skey/skeykeys \
			${PKG_SYSCONFDIR}/skeykeys

REPLACE_PERL=		skeyprune.pl

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

post-install:
	${RANLIB} ${DESTDIR}${PREFIX}/lib/libskey.a

.include "../../mk/bsd.pkg.mk"
