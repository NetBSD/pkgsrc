# $NetBSD: Makefile,v 1.2 2002/10/20 17:45:59 seb Exp $
#

DISTNAME=	nkf-1.7
PKGNAME=	p5-nkf-1.7
SVR4_PKGNAME=	p5nkf
CATEGORIES=	japanese converters
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/nkf/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	Perl library for Network Kanji code conversion Filter

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/NKF/.packlist

WRKSRC=		${WRKDIR}/${DISTNAME}/NKF

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
