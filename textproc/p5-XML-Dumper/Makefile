# $NetBSD: Makefile,v 1.17 2016/06/08 19:24:42 wiz Exp $

DISTNAME=	XML-Dumper-0.81
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Simple/
COMMENT=	Perl to XML structure input/output engine

DEPENDS+=	p5-XML-Parser>=2.16:../../textproc/p5-XML-Parser

PERL5_PACKLIST=		auto/XML/Dumper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
