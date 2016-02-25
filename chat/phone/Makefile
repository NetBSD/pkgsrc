# $NetBSD: Makefile,v 1.7 2016/02/25 11:28:58 jperkin Exp $

DISTNAME=	phone-2.0
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.astron.com/pub/phone/
DIST_SUBDIR=	phone-2.0nb1

MAINTAINER=	christos@NetBSD.org
HOMEPAGE=	ftp://ftp.astron.com/pub/phone/
COMMENT=	Multi-person chat program, like VMS phone
LICENSE=	generic-nonlicense

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man1 sbin

# needs utmpx unless someone wants to patch legacy utmp support in
BROKEN_ON_PLATFORM=	OpenBSD-*-*

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wa,--fatal-warnings
CFLAGS.Darwin+=			-DINFTIM=-1

post-install:
	${INSTALL_MAN} ${WRKSRC}/phone.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/phone.1

.include "../../mk/bsd.pkg.mk"
