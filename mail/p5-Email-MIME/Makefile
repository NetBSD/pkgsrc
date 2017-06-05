# $NetBSD: Makefile,v 1.29 2017/06/05 14:24:04 ryoon Exp $

DISTNAME=		Email-MIME-1.940
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-MIME/
COMMENT=		Perl module for easy MIME message parsing
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Email-MIME-ContentType>=1.016:../../mail/p5-Email-MIME-ContentType
DEPENDS+=		p5-Email-MIME-Encodings>=1.314:../../mail/p5-Email-MIME-Encodings
DEPENDS+=		p5-Email-MessageID-[0-9]*:../../mail/p5-Email-MessageID
# Email::Simple-2.100 contains both: Email::Simple and Email::Simple::Creator
DEPENDS+=		p5-Email-Simple>=2.206:../../mail/p5-Email-Simple
#DEPENDS+=		{perl>=5.8.1,p5-Encode>=1.98.01}:../../textproc/p5-Encode
DEPENDS+=		p5-MIME-Types>=1.13:../../mail/p5-MIME-Types
#BUILD_DEPENDS+=		{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

#CONFLICTS+=		p5-Email-MIME-Creator-[0-9]*
#CONFLICTS+=		p5-Email-MIME-Modifier-[0-9]*

#SUPERSEDES+=		p5-Email-MIME-Creator<=1.444
#SUPERSEDES+=		p5-Email-MIME-Modifier<=1.456

PERL5_PACKLIST=		auto/Email/MIME/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
