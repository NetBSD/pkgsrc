# $NetBSD: Makefile,v 1.7 2011/08/14 13:25:22 obache Exp $

DISTNAME=	Email-Date-1.103
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/dist/Email-Date
COMMENT=	Find and Format Date Headers

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Email-Simple>=1.9:../../mail/p5-Email-Simple
DEPENDS+=	p5-Time-Piece>=1.08:../../time/p5-Time-Piece
DEPENDS+=	p5-Time-Local>=1.07:../../time/p5-Time-Local
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate
DEPENDS+=	p5-Email-Abstract>=2.10:../../mail/p5-Email-Abstract
DEPENDS+=	p5-Email-Date-Format>=1.000:../../mail/p5-Email-Date-Format

PERL5_PACKLIST=	auto/Email/Date/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
