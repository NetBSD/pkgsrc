# $NetBSD: Makefile,v 1.5 2004/01/20 12:10:29 agc Exp $
#

DISTNAME=	nkf-1.7
PKGNAME=	p5-nkf-1.7
SVR4_PKGNAME=	p5nkf
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/nkf/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Perl library for Network Kanji code conversion Filter

WRKSRC=			${WRKDIR}/${DISTNAME}/NKF
USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/NKF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
