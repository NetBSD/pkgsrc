# $NetBSD: Makefile,v 1.11 2013/07/21 15:06:51 wen Exp $
#

DISTNAME=		Net-FTPSSL-0.22
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5 security
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://developer.berlios.de/projects/net-ftpssl/
COMMENT=		Perl FTP over SSL/TLS class
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-IO-Socket-SSL>=1.08:../../security/p5-IO-Socket-SSL
DEPENDS+=		p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/FTPSSL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
