# $NetBSD: Makefile,v 1.15 2008/10/19 19:18:56 he Exp $

DISTNAME=		Text-ChaSen-1.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
SVR4_PKGNAME=		p5tcs
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		http://www.daionet.gr.jp/~knok/chasen/

PATCHFILES=		ChaSen.pm-1.03-pod-fix.diff
PATCH_SITES=		http://www.daionet.gr.jp/~knok/chasen/

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~knok/chasen/
COMMENT=		Perl5 module to use ChaSen

USE_LANGUAGES=		c c++
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/ChaSen/.packlist

.include "../../textproc/chasen/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
