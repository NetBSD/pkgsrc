# $NetBSD: Makefile,v 1.8 2012/10/03 00:20:11 asau Exp $

DISTNAME=	jcode.pl-2.13
PKGNAME=	${DISTNAME:S/jcode.pl/jcode-perl/}
PKGREVISION=	4
SVR4_PKGNAME=	jcopl
CATEGORIES=	japanese converters perl5
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/ \
		ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/
EXTRACT_SUFX=	# empty

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.srekcah.org/jcode/
COMMENT=	Perl library for Japanese character code conversion

CONFLICTS+=	p5-jcode-[0-9]*

WRKSRC=			${WRKDIR}

NO_BUILD=		yes
NO_CONFIGURE=		yes
PERL5_CONFIGURE=	NO

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
		${DESTDIR}${PERL5_INSTALLVENDORLIB}/jcode.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
