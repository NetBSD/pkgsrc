# $NetBSD: Makefile,v 1.1.1.1 2005/09/14 14:30:17 tv Exp $

DISTNAME=	XML-Dumper-0.79
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xdu
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Simple/
COMMENT=	Perl to XML structure input/output engine

DEPENDS+=	p5-XML-Parser>=2.16:../../textproc/p5-XML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/Dumper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
