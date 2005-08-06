# $NetBSD: Makefile,v 1.12 2005/08/06 06:19:33 jlam Exp $

DISTNAME=		Text-Kakasi-1.05
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tka
PKGREVISION=		1
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		http://www.daionet.gr.jp/~knok/kakasi/

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/kakasi/
COMMENT=		Perl5 module to use Kakasi

PERL5_PACKLIST=		auto/Text/Kakasi/.packlist

.include "../../textproc/kakasi/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
