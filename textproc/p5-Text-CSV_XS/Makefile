# $NetBSD: Makefile,v 1.20 2008/11/22 00:11:41 he Exp $
#

DISTNAME=	Text-CSV_XS-0.58
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tcx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-CSV_XS/
COMMENT=	Routines for composition and decomposition of comma-separated values

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/CSV_XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
