# $NetBSD: Makefile,v 1.20 2019/06/30 20:17:06 nia Exp $

DISTNAME=	XML-Atom-Stream-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Atom-Stream
COMMENT=	Client interface for AtomStream

#really: Test::More >= 0.32
#BUILD_DEPENDS+=	{perl>=5.6.2,p5-Test-Simple>=0.32}:../../devel/p5-Test-Simple
DEPENDS+=	p5-libwww>=5.0:../../www/p5-libwww
DEPENDS+=	p5-XML-SAX>=0.12:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-Handler-Trees>=0.02:../../textproc/p5-XML-Handler-Trees
DEPENDS+=	p5-XML-Atom>=0.20:../../textproc/p5-XML-Atom

PERL5_PACKLIST=		auto/XML/Atom/Stream/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
