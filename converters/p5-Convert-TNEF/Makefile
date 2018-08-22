# $NetBSD: Makefile,v 1.31 2018/08/22 09:43:06 wiz Exp $

DISTNAME=	Convert-TNEF-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Convert-TNEF/
COMMENT=	Perl5 module interface to read TNEF files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/TNEF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
