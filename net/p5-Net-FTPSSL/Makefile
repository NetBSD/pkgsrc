# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:39 joerg Exp $
#

DISTNAME=		Net-FTPSSL-0.04
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5 security
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		dieter.NetBSD@pandora.be
HOMEPAGE=		http://developer.berlios.de/projects/net-ftpssl/
COMMENT=		Perl FTP over SSL/TLS class

DEPENDS+=		p5-IO-Socket-SSL>=0.96:../../security/p5-IO-Socket-SSL

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/FTPSSL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
