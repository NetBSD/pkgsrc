# $NetBSD: Makefile,v 1.2 2002/10/20 14:56:32 seb Exp $
# FreeBSD Id: Makefile,v 1.2 1999/01/17 10:56:40 vanilla Exp $

DISTNAME=	jcode.pl-2.13
PKGNAME=	p5-jcode-2.13
SVR4_PKGNAME=	p5jc2
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	# not available
COMMENT=	Perl library for Japanese character code conversion

USE_BUILDLINK2=		YES

WRKSRC=			${WRKDIR}
NO_BUILD=		# defined
NO_CONFIGURE=		# defined
PERL5_CONFIGURE=	NO
EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} .

do-install:
	${INSTALL_DATA_DIR} ${PERL5_SITELIB}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${PERL5_SITELIB}/jcode.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
