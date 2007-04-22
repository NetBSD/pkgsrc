# $NetBSD: Makefile,v 1.2 2007/04/22 20:46:39 heinz Exp $

DISTNAME=		Email-MIME-1.859
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5emm
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-MIME/
COMMENT=		Perl module for easy MIME message parsing

DEPENDS+=		p5-Email-MIME-ContentType>=1.011:../../mail/p5-Email-MIME-ContentType
DEPENDS+=		p5-Email-MIME-Encodings>=1.3:../../mail/p5-Email-MIME-Encodings
DEPENDS+=		p5-Email-Simple>=1.995:../../mail/p5-Email-Simple
DEPENDS+=		p5-MIME-Types>=1.13:../../mail/p5-MIME-Types
BUILD_DEPENDS+=		p5-Test-Simple>=0.47:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Email/MIME/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
