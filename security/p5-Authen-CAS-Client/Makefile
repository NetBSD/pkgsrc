# $NetBSD: Makefile,v 1.18 2018/08/22 09:46:19 wiz Exp $
#

DISTNAME=	Authen-CAS-Client-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Authen-CAS-Client/
COMMENT=	Perl 5 module providing an interface for JA-SIG's CAS
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Authen/CAS/Client/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

BUILD_DEPENDS+=	p5-Test-MockObject-[0-9]*:../../devel/p5-Test-MockObject
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
