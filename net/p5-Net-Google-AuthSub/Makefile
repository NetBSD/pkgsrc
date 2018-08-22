# $NetBSD: Makefile,v 1.10 2018/08/22 09:46:00 wiz Exp $

DISTNAME=		Net-Google-AuthSub-0.5
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-Google-AuthSub/
COMMENT=		Perl module for interacting with sites using Google-style AuthSub
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Net/Google/AuthSub/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
