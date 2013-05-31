# $NetBSD: Makefile,v 1.12 2013/05/31 12:42:19 wiz Exp $

DISTNAME=	XML-Dumper-0.81
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5xdu
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Simple/
COMMENT=	Perl to XML structure input/output engine

DEPENDS+=	p5-XML-Parser>=2.16:../../textproc/p5-XML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/Dumper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
