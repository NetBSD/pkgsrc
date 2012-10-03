# $NetBSD: Makefile,v 1.15.2.1 2012/10/03 12:07:19 spz Exp $
#

DISTNAME=	Wx-Perl-DataWalker-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Wx-Perl-DataWalker/
COMMENT=	Shows a relatively simple Perl data structure browser
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-XSAccessor>=0.06:../../devel/p5-Class-XSAccessor
DEPENDS+=	p5-Devel-Size>=0.71:../../devel/p5-Devel-Size
DEPENDS+=	p5-YAML-LibYAML>=0.32:../../textproc/p5-YAML-LibYAML

USE_TOOLS+=	perl

PERL5_PACKLIST=		auto/Wx/Perl/DataWalker/.packlist

.include "../../x11/p5-Wx/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
