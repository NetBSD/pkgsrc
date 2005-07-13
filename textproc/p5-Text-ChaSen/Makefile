# $NetBSD: Makefile,v 1.10 2005/07/13 18:01:41 jlam Exp $

DISTNAME=		Text-ChaSen-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5tcs
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		http://www.daionet.gr.jp/~knok/chasen/

PATCHFILES=		ChaSen.pm-1.03-pod-fix.diff
PATCH_SITES=		http://www.daionet.gr.jp/~knok/chasen/

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/chasen/
COMMENT=		Perl5 module to use ChaSen

PERL5_PACKLIST=		auto/Text/ChaSen/.packlist

.include "../../textproc/chasen/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
