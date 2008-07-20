# $NetBSD: Makefile,v 1.3 2008/07/20 16:09:34 heinz Exp $

DISTNAME=	Email-Date-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/dist/Email-Date
COMMENT=	Find and Format Date Headers

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Email-Simple>=1.9:../../mail/p5-Email-Simple
DEPENDS+=	p5-Time-Piece>=1.08:../../time/p5-Time-Piece
DEPENDS+=	p5-Time-Local>=1.07:../../time/p5-Time-Local
DEPENDS+=	p5-TimeDate>=1.16:../../time/p5-TimeDate

PERL5_PACKLIST=	auto/Email/Date/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
