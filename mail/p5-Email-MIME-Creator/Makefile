# $NetBSD: Makefile,v 1.7 2009/04/30 20:38:12 sno Exp $

DISTNAME=	Email-MIME-Creator-1.456
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-MIME-Creator/
COMMENT=	Email::MIME constructor for starting anew
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Email-MIME>=1.82:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-MIME-Encodings>=1.313:../../mail/p5-Email-MIME-Encodings
DEPENDS+=	p5-Email-MIME-Modifier>=1.440:../../mail/p5-Email-MIME-Modifier
DEPENDS+=	p5-Email-Simple>=1.92:../../mail/p5-Email-Simple
DEPENDS+=	p5-Email-Simple-Creator>=1.4:../../mail/p5-Email-Simple-Creator
DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Email/MIME/Creator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
