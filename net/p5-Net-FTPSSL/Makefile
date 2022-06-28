# $NetBSD: Makefile,v 1.30 2022/06/28 11:35:09 wiz Exp $

DISTNAME=		Net-FTPSSL-0.42
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		net perl5 security
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://developer.berlios.de/projects/net-ftpssl/
COMMENT=		Perl FTP over SSL/TLS class
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-IO-Socket-SSL>=1.26:../../security/p5-IO-Socket-SSL
DEPENDS+=		p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/FTPSSL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
