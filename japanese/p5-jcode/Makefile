# $NetBSD: Makefile,v 1.6 2001/09/09 20:36:31 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1999/01/17 10:56:40 vanilla Exp $

DISTNAME=	jcode.pl-2.13
PKGNAME=	p5-jcode-2.13
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	# not available
COMMENT=	Perl library for Japanese character code conversion

USE_PERL5=	yes
WRKSRC=		${WRKDIR}
NO_BUILD=	# defined
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} .

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${PREFIX}/lib/perl5/site_perl/jcode.pl

.include "../../mk/bsd.pkg.mk"
