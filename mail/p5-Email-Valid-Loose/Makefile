# $NetBSD: Makefile,v 1.4 2011/08/14 13:25:24 obache Exp $

DISTNAME=		Email-Valid-Loose-0.05
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/perldoc?Email::Valid::Loose
COMMENT=		Email::Valid which allows dot before at mark

DEPENDS+=		p5-Email-Valid>=0.17:../../mail/p5-Email-Valid

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Email/Valid/Loose/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
