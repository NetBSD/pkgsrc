# $NetBSD: Makefile,v 1.9 2005/02/19 11:29:18 wiz Exp $

DISTNAME=		Text-Kakasi-1.05
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tka
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		http://www.daionet.gr.jp/~knok/kakasi/

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/kakasi/
COMMENT=		Perl5 module to use Kakasi

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Kakasi/.packlist

.include "../../textproc/kakasi/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
