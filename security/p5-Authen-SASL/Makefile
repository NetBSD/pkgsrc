# $NetBSD: Makefile,v 1.13 2009/01/11 14:30:08 he Exp $
#

DISTNAME=	Authen-SASL-2.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Authen-SASL/
COMMENT=	Perl module to handle SASL authentication

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Authen/SASL/.packlist
MAKE_PARAMS+=	< /dev/null

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
