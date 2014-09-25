# $NetBSD: Makefile,v 1.12 2014/09/25 13:02:30 jperkin Exp $
#

DISTNAME=	bulk_mailer-1.13
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://cs.utk.edu/pub/moore/bulk_mailer/

MAINTAINER=	abs@NetBSD.org
COMMENT=	Assist in delivery of mail to large numbers of recipients

HAS_CONFIGURE=	YES
BUILD_TARGET=	bulk_mailer

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bulk_mailer \
		${DESTDIR}${PREFIX}/bin/bulk_mailer
	${INSTALL_MAN} ${WRKSRC}/bulk_mailer.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/bulk_mailer.1

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
