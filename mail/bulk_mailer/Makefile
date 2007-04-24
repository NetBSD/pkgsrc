# $NetBSD: Makefile,v 1.9 2007/04/24 22:31:19 abs Exp $
#

DISTNAME=	bulk_mailer-1.13
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://cs.utk.edu/pub/moore/bulk_mailer/

MAINTAINER=	abs@NetBSD.org
COMMENT=	Assist in delivery of mail to large numbers of recipients

HAS_CONFIGURE=	YES
BUILD_TARGET=	bulk_mailer

CPPFLAGS.SunOS+=	-DPIPECOMMAND=\"/usr/sbin/sendmail -bs %s\"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bulk_mailer ${PREFIX}/bin/bulk_mailer
	${INSTALL_MAN} ${WRKSRC}/bulk_mailer.1 ${PREFIX}/${PKGMANDIR}/man1/bulk_mailer.1

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
