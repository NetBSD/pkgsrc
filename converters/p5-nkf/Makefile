# $NetBSD: Makefile,v 1.4 2003/07/17 21:27:28 grant Exp $
#

DISTNAME=	nkf-1.7
PKGNAME=	p5-nkf-1.7
SVR4_PKGNAME=	p5nkf
WRKSRC=		${WRKDIR}/${DISTNAME}/NKF
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/nkf/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Perl library for Network Kanji code conversion Filter

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/NKF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
