# $NetBSD: Makefile,v 1.13 2014/09/23 14:50:03 jperkin Exp $
#

DISTNAME=		bounce-0.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Tool to forward TCP connection from one IP to another

CONFLICTS+=		majordomo-*

WRKSRC=			${WRKDIR}/bounce
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

BUILD_TARGET=		bounce

LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bounce ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bounce.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
