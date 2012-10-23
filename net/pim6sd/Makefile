# $NetBSD: Makefile,v 1.22 2012/10/23 17:18:58 asau Exp $

DISTNAME=	pim6sd-20031021a
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	IPv6 PIM sparse mode daemon

USE_BSD_MAKEFILE=	yes
USE_FEATURES+=		inet6

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6sd/
USE_TOOLS+=	lex yacc

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/cat5 ${PKGMANDIR}/cat8 \
			${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

CONFLICTS=	mcast-tools-[0-9]*

post-install:
	${INSTALL_MAN} ${WRKSRC}/pim6stat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
