# $NetBSD: Makefile,v 1.1.2.1 2014/01/02 22:03:26 tron Exp $

DISTNAME=	phone-2.0
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.astron.com/pub/phone/
DIST_SUBDIR=	phone-2.0nb1

MAINTAINER=	christos@NetBSD.org
HOMEPAGE=	ftp://ftp.astron.com/pub/phone/
COMMENT=	Multi-person chat program, like VMS phone
LICENSE=	generic-nonlicense

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man1 sbin

post-install:
	${INSTALL_MAN} ${WRKSRC}/phone.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/phone.1

.include "../../mk/bsd.pkg.mk"
