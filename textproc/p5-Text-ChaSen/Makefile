# $NetBSD: Makefile,v 1.4 2003/07/21 17:27:41 martti Exp $

DISTNAME=		Text-ChaSen-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5tcs
CATEGORIES=		japanese textproc
MASTER_SITES=		http://www.daionet.gr.jp/~knok/chasen/

PATCHFILES=		ChaSen.pm-1.03-pod-fix.diff
PATCH_SITES=		http://www.daionet.gr.jp/~knok/chasen/

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/chasen/
COMMENT=		Perl5 module to use ChaSen

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/ChaSen/.packlist

.include "../../textproc/chasen/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
