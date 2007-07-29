# $NetBSD: Makefile,v 1.1.1.1 2007/07/29 12:08:52 adrianp Exp $

DISTNAME=	Email-MIME-Creator-1.41
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Email-MIME-Creator/
COMMENT=	Email::MIME constructor for starting anew

DEPENDS+=	p5-Email-Simple>=1.92:../../mail/p5-Email-Simple
DEPENDS+=	p5-Email-Simple-Creator>=1.4:../../mail/p5-Email-Simple-Creator
DEPENDS+=	p5-Email-MIME>=1.82:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-MIME-Modifier>=1.42:../../mail/p5-Email-MIME-Modifier
DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Email/MIME/Creator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
