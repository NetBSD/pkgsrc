# $NetBSD: Makefile,v 1.1.1.1 2007/07/29 11:27:58 adrianp Exp $

DISTNAME=	Email-MIME-Modifier-1.42
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Email-MIME-Modifier/
COMMENT=	Modify Email::MIME Objects Easily

DEPENDS+=	p5-Email-MIME-Encodings>=1.3:../../mail/p5-Email-MIME-Encodings
DEPENDS+=	p5-Email-MIME>=1.82:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-MessageID>=1.2:../../mail/p5-Email-MessageID
DEPENDS+=	p5-Email-MIME-ContentType>=1.0:../../mail/p5-Email-MIME-ContentType
DEPENDS+=	p5-Email-Simple>=1.92:../../mail/p5-Email-Simple
DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Email/MIME/Modifier/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
