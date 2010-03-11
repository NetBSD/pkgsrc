# $NetBSD: Makefile,v 1.5 2010/03/11 10:59:58 sno Exp $

DISTNAME=	Catalyst-View-Email-0.23
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-Email/
COMMENT=	Send Templated Email from Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Authen-SASL>=2.13:../../security/p5-Authen-SASL
DEPENDS+=    	p5-Catalyst-Runtime>=5.7:../../www/p5-Catalyst-Runtime
DEPENDS+=    	p5-Catalyst-View-Mason-[0-9]*:../../www/p5-Catalyst-View-Mason
DEPENDS+=    	p5-Catalyst-View-TT-[0-9]*:../../www/p5-Catalyst-View-TT
#DEPENDS+=    	p5-Class-C3>=0:../../devel/p5-Class-C3
DEPENDS+=    	p5-Email-MIME>=1.900:../../mail/p5-Email-MIME
DEPENDS+=    	p5-Email-Sender>=0.100110:../../mail/p5-Email-Sender
# Email::MIME-1.900 merges Email::MIME::Creator
#DEPENDS+=    	p5-Email-MIME-Creator>=1.455:../../mail/p5-Email-MIME-Creator
DEPENDS+=	{perl>=5.10.1,p5-MIME-Base64>=3.08}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Moose>=0.93:../../devel/p5-Moose
DEPENDS+=	p5-parent>=0.223:../../devel/p5-parent

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/View/Email/.packlist

# M:I:AI switch - this is EU:MM module
#MAKE_ENV+=       PERL_AUTOINSTALL=--skipdeps

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
