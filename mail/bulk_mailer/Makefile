# $NetBSD: Makefile,v 1.6 2005/06/16 06:58:02 jlam Exp $
#

DISTNAME=	bulk_mailer-1.13
CATEGORIES=	mail
MASTER_SITES=	ftp://cs.utk.edu/pub/moore/bulk_mailer/

MAINTAINER=	abs@NetBSD.org
COMMENT=	Assist in delivery of mail to large numbers of recipients

HAS_CONFIGURE=	YES
BUILD_TARGET=	bulk_mailer

CPPFLAGS.SunOS+=	-DPIPECOMMAND=\"/usr/sbin/sendmail -bs %s\"

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bulk_mailer ${PREFIX}/bin/bulk_mailer
	${INSTALL_MAN} ${WRKSRC}/bulk_mailer.1 ${PREFIX}/man/man1/bulk_mailer.1

.include "../../mk/bsd.pkg.mk"
