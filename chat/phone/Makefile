# $NetBSD: Makefile,v 1.4 2015/02/23 18:19:34 joerg Exp $

DISTNAME=	phone-2.0
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.astron.com/pub/phone/
DIST_SUBDIR=	phone-2.0nb1

MAINTAINER=	christos@NetBSD.org
HOMEPAGE=	ftp://ftp.astron.com/pub/phone/
COMMENT=	Multi-person chat program, like VMS phone
LICENSE=	generic-nonlicense

INSTALLATION_DIRS=	bin libexec ${PKGMANDIR}/man1 sbin


.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-Wa,--fatal-warnings
CFLAGS+=		-DINFTIM=-1
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/phone.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/phone.1

.include "../../mk/bsd.pkg.mk"
