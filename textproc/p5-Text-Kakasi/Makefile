# $NetBSD: Makefile,v 1.6 2004/10/03 00:18:20 tv Exp $

DISTNAME=		Text-Kakasi-1.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=		p5tka
CATEGORIES=		japanese textproc
MASTER_SITES=		http://www.daionet.gr.jp/~knok/kakasi/

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/kakasi/
COMMENT=		Perl5 module to use Kakasi

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Kakasi/.packlist

.include "../../textproc/kakasi/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
