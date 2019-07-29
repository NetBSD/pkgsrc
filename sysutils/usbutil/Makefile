# $NetBSD: Makefile,v 1.19 2019/07/29 11:19:56 micha Exp $

DISTNAME=	usbutil-0.5
PKGREVISION=	6
CATEGORIES=	sysutils
#MASTER_SITES=	ftp://ftp.augustsson.net/pub/netbsd/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	USB developer utilities
LICENSE=	2-clause-bsd

INSTALLATION_DIRS+=	${PKGMANDIR}/man8

post-install:
	${INSTALL_MAN} ${WRKSRC}/usbgen.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/usbgen.8

.include "../../mk/bsd.pkg.mk"
