# $NetBSD: Makefile,v 1.3 2008/07/20 16:09:34 heinz Exp $

DISTNAME=	Email-Simple-Creator-1.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Simple-Creator/
COMMENT=	Constructor to Email::Simple for creating messages from scratch

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Email-Simple>=0:../../mail/p5-Email-Simple
DEPENDS+=	p5-Email-Date>=0:../../mail/p5-Email-Date
DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Email/Simple/Creator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
