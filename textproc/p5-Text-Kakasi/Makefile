# $NetBSD: Makefile,v 1.4 2003/07/21 17:27:42 martti Exp $

DISTNAME=		Text-Kakasi-1.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tka
CATEGORIES=		japanese textproc
MASTER_SITES=		http://www.daionet.gr.jp/~knok/kakasi/

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/kakasi/
COMMENT=		Perl5 module to use Kakasi

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Kakasi/.packlist

.include "../../textproc/kakasi/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
