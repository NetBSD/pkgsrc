# $NetBSD: Makefile,v 1.29 2017/06/05 14:24:04 ryoon Exp $

DISTNAME=		Email-Simple-2.213
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-Simple/
COMMENT=		Perl5 module for simple parsing of RFC2822 message format and headers
LICENSE=		${PERL5_LICENSE}

# versions before 1.857 meddled in the guts of Email::Simple
CONFLICTS+=		p5-Email-MIME<1.857
CONFLICTS+=		p5-Email-Simple-Creator-[0-9]*

SUPERSEDES+=		p5-Email-Simple-Creator<=1.424nb1

DEPENDS+=		p5-Email-Date-Format-[0-9]*:../../mail/p5-Email-Date-Format

PERL5_PACKLIST=		auto/Email/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
