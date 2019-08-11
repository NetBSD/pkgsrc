# $NetBSD: Makefile,v 1.15 2019/08/11 13:23:53 wiz Exp $

DISTNAME=	XML-FeedPP-0.95
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-FeedPP
COMMENT=	Perl 5 module to parse/write/merge/edit RSS/RDF/Atom syndication feeds
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=			# empty
PERL5_PACKLIST=			auto/XML-FeedPP/.packlist
CHECK_PORTABILITY_SKIP+=	make-dist.sh

DEPENDS+=	p5-XML-TreePP>=0.39:../../textproc/p5-XML-TreePP

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
