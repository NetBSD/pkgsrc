# $NetBSD: Makefile,v 1.4 2003/07/17 21:27:26 grant Exp $
# FreeBSD Id: Makefile,v 1.2 1999/01/17 10:56:40 vanilla Exp $

DISTNAME=	jcode.pl-2.13
PKGNAME=	p5-jcode-2.13
SVR4_PKGNAME=	p5jc2
WRKSRC=		${WRKDIR}
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Perl library for Japanese character code conversion

USE_BUILDLINK2=		YES

NO_BUILD=		# defined
NO_CONFIGURE=		# defined
PERL5_CONFIGURE=	NO
EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} .

do-install:
	${INSTALL_DATA_DIR} ${PERL5_SITELIB}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${PERL5_SITELIB}/jcode.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
