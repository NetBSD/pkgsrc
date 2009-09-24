# $NetBSD: Makefile,v 1.4 2009/09/24 06:50:16 sno Exp $

DISTNAME=	Catalyst-View-Email-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-Email/
COMMENT=	Send Templated Email from Catalyst

DEPENDS+=    	p5-Catalyst-Runtime>=5.7:../../www/p5-Catalyst-Runtime
DEPENDS+=    	p5-Class-C3>=0:../../devel/p5-Class-C3
DEPENDS+=    	p5-Email-Send>=2.185:../../mail/p5-Email-Send
DEPENDS+=    	p5-Email-MIME>=1.859:../../mail/p5-Email-MIME
DEPENDS+=    	p5-Email-MIME-Creator>=1.455:../../mail/p5-Email-MIME-Creator
DEPENDS+=    	p5-Catalyst-View-TT>=0:../../www/p5-Catalyst-View-TT

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/View/Email/.packlist

MAKE_ENV+=       PERL_AUTOINSTALL=--skipdeps

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
