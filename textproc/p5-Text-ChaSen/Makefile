# $NetBSD: Makefile,v 1.7 2004/11/12 00:32:23 seb Exp $

DISTNAME=		Text-ChaSen-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5tcs
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		http://www.daionet.gr.jp/~knok/chasen/

PATCHFILES=		ChaSen.pm-1.03-pod-fix.diff
PATCH_SITES=		http://www.daionet.gr.jp/~knok/chasen/

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/chasen/
COMMENT=		Perl5 module to use ChaSen

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/ChaSen/.packlist

.include "../../textproc/chasen/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
