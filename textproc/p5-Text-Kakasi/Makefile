# $NetBSD: Makefile,v 1.2 2002/10/05 03:20:34 wiz Exp $

DISTNAME=		Text-Kakasi-1.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tka
CATEGORIES=		japanese textproc
MASTER_SITES=		http://www.daionet.gr.jp/~knok/kakasi/

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/kakasi/
COMMENT=		perl5 module to use Kakasi

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Kakasi/.packlist

.include "../../textproc/kakasi/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
