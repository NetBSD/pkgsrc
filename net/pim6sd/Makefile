# $NetBSD: Makefile,v 1.25 2020/03/18 17:59:20 joerg Exp $

DISTNAME=	pim6sd-20031021a
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	IPv6 PIM sparse mode daemon

USE_BSD_MAKEFILE=	yes
USE_FEATURES+=		inet6

CWARNFLAGS.clang=	-Wno-error=knr-promoted-parameter \
			-Wno-error=address-of-packed-member \
			-Wno-error=pointer-sign
MAKE_ENV+=		CWARNFLAGS.clang=${CWARNFLAGS.clang:Q}

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6sd/
USE_TOOLS+=	lex yacc

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/cat5 ${PKGMANDIR}/cat8 \
			${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

CONFLICTS=	mcast-tools-[0-9]*

post-install:
	${INSTALL_MAN} ${WRKSRC}/pim6stat.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
