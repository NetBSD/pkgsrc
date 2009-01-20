# $NetBSD: Makefile,v 1.14 2009/01/20 06:24:03 seb Exp $
#

DISTNAME=	Authen-SASL-2.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Authen-SASL/
COMMENT=	Perl module to handle SASL authentication

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Authen/SASL/.packlist
MAKE_PARAMS+=	< /dev/null

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
