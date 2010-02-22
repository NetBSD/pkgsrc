# $NetBSD: Makefile,v 1.15 2010/02/22 15:56:28 sno Exp $
#

DISTNAME=	Authen-SASL-2.13
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Authen-SASL/
COMMENT=	Perl module to handle SASL authentication
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Authen/SASL/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled
#MAKE_PARAMS+=	< /dev/null

DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
# recommended
DEPENDS+=	p5-GSSAPI-[0-9]*:../../security/p5-GSSAPI

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
