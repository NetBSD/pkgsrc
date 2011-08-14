# $NetBSD: Makefile,v 1.14 2011/08/14 13:25:26 obache Exp $

DISTNAME=		Mail-SPF-Query-1.999
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5msq
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://www.openspf.org/
COMMENT=		Perl module for Sender-Policy-Framework queries

DEPENDS+=		p5-Net-DNS>=0.46:../../net/p5-Net-DNS
DEPENDS+=		p5-Net-CIDR-Lite>=0.15:../../net/p5-Net-CIDR-Lite
DEPENDS+=		p5-Sys-Hostname-Long-[0-9]*:../../sysutils/p5-Sys-Hostname-Long
# needed URI::Escape >= 3.20 until 1.991. We keep the requirement.
DEPENDS+=		p5-URI>=1.18:../../www/p5-URI

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Mail/SPF/Query/.packlist
USE_LANGUAGES=		# empty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
