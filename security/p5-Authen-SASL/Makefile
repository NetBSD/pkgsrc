# $NetBSD: Makefile,v 1.9 2008/06/20 01:09:34 joerg Exp $
#

DISTNAME=	Authen-SASL-2.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://search.cpan.org/dist/Authen-SASL/
COMMENT=	Perl module to handle SASL authentication

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Authen/SASL/.packlist
MAKE_PARAMS+=	< /dev/null

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
