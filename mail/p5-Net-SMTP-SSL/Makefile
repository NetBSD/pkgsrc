# $NetBSD: Makefile,v 1.3 2011/08/14 13:25:27 obache Exp $
#

DISTNAME=		Net-SMTP-SSL-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		mail perl5 security
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-SMTP-SSL/
COMMENT=		Perl5 module providing SSL support for Net::SMTP
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/SMTP/SSL/.packlist

DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
