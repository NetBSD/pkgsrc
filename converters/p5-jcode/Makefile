# $NetBSD: Makefile,v 1.9 2005/03/24 21:12:52 wiz Exp $

DISTNAME=	jcode.pl-2.13
PKGNAME=	p5-jcode-2.13
SVR4_PKGNAME=	p5jc2
PKGREVISION=	1
CATEGORIES=	japanese converters perl5
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Perl library for Japanese character code conversion

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		YES

NO_BUILD=		# defined
NO_CONFIGURE=		# defined
PERL5_CONFIGURE=	NO
EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} .

do-install:
	${INSTALL_DATA_DIR} ${PERL5_SITELIB}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${PERL5_SITELIB}/jcode.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
