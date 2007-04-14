# $NetBSD: Makefile,v 1.1.1.1 2007/04/14 19:10:18 kleink Exp $

DISTNAME=	Text-vCard-2.00
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tva
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-vCard/
COMMENT=	parse, edit and create vCards (RFC 2426)

# for MIME::QuotedPrint
DEPENDS+=	p5-MIME-Base64>=3.07:../../converters/p5-MIME-Base64
DEPENDS+=	p5-File-Slurp>=9999.04:../../devel/p5-File-Slurp
DEPENDS+=	p5-Text-vFile-asData>=0.05:../../textproc/p5-Text-vFile-asData

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
