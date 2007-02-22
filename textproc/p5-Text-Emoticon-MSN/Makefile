# $NetBSD: Makefile,v 1.2 2007/02/22 12:22:59 wiz Exp $

DISTNAME=       Text-Emoticon-MSN-0.04
PKGNAME=        p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Text-Emoticon-MSN/
COMMENT=	Emoticon filter of MSN Messenger

DEPENDS+=       {perl>=5.7.3,p5-Test-Simple>=0.32}:../../devel/p5-Test-Simple
DEPENDS+=       p5-Text-Emoticon>=0.02:../../textproc/p5-Text-Emoticon

PERL5_PACKLIST=		auto/Text/Emoticon/MSN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
