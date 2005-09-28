# $NetBSD: Makefile,v 1.12 2005/09/28 20:52:18 rillig Exp $

DISTNAME=	jcode.pl-2.13
PKGNAME=	p5-jcode-2.13
SVR4_PKGNAME=	p5jc2
PKGREVISION=	2
CATEGORIES=	japanese converters perl5
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Perl library for Japanese character code conversion

WRKSRC=			${WRKDIR}

NO_BUILD=		yes
NO_CONFIGURE=		yes
PERL5_CONFIGURE=	NO
EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} .

do-install:
	${INSTALL_DATA_DIR} ${PERL5_INSTALLVENDORLIB}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${PERL5_INSTALLVENDORLIB}/jcode.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
