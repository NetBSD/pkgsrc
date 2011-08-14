# $NetBSD: Makefile,v 1.8 2011/08/14 13:25:22 obache Exp $

DISTNAME=	Catalyst-View-Email-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-Email/
COMMENT=	Send Templated Email from Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Authen-SASL>=2.13:../../security/p5-Authen-SASL
DEPENDS+=	p5-Catalyst-Runtime>=5.70000:../../www/p5-Catalyst-Runtime
# Email::MIME-1.900 merges Email::MIME::Creator
DEPENDS+=	p5-Email-MIME>=1.900:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-Sender>=0.100110:../../mail/p5-Email-Sender
DEPENDS+=	{perl>=5.10.1,p5-MIME-Base64>=3.08}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Moose>=0.93:../../devel/p5-Moose
DEPENDS+=	{perl>=5.12.0,p5-parent>=0.223}:../../devel/p5-parent

BUILD_DEPENDS+=	p5-Catalyst-View-Mason-[0-9]*:../../www/p5-Catalyst-View-Mason
BUILD_DEPENDS+=	p5-Catalyst-View-TT-[0-9]*:../../www/p5-Catalyst-View-TT
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/View/Email/.packlist

# M:I:AI switch - this is EU:MM module
#MAKE_ENV+=       PERL_AUTOINSTALL=--skipdeps

PERL5_MODULE_TYPE=	Module::Install::Bundled
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
