# $NetBSD: Makefile,v 1.13 2022/06/28 11:34:22 wiz Exp $
#

DISTNAME=	mailsort-1.26
PKGREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AZ/AZS/mailsort/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://metacpan.org/release/AZS/mailsort-1.26
COMMENT=	Sort mbox mail folders by date

LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
REPLACE_PERL+=		mailsort
USE_LANGUAGES=		# none
USE_TOOLS=		perl pod2man

do-build:
	pod2man ${WRKSRC}/mailsort > ${WRKSRC}/mailsort.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mailsort ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/mailsort.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
