# $NetBSD: Makefile,v 1.2 2024/02/28 08:52:34 wen Exp $

DISTNAME=		Mail-DMARC-1.20240214
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Mail::DMARC
COMMENT=		Perl implementation of DMARC
LICENSE=		${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-File-ShareDir-Install>=0.06:../../devel/p5-File-ShareDir-Install
DEPENDS+=		p5-Config-Tiny>=0:../../devel/p5-Config-Tiny
DEPENDS+=		p5-DBD-SQLite>=1.31:../../databases/p5-DBD-SQLite
DEPENDS+=		p5-DBIx-Simple>=1.35:../../databases/p5-DBIx-Simple
DEPENDS+=		p5-Data-Dumper>=0:../../devel/p5-Data-Dumper
DEPENDS+=		p5-Email-MIME>=0:../../mail/p5-Email-MIME
DEPENDS+=		p5-Email-Sender>=1.300032:../../mail/p5-Email-Sender
DEPENDS+=		p5-Email-Simple>=0:../../mail/p5-Email-Simple
DEPENDS+=		p5-File-ShareDir>=0:../../devel/p5-File-ShareDir
DEPENDS+=		p5-HTTP-Tiny>=0:../../www/p5-HTTP-Tiny
DEPENDS+=		p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=		p5-Mail-DKIM>=0:../../mail/p5-Mail-DKIM
DEPENDS+=		p5-Net-DNS>=0:../../net/p5-Net-DNS
DEPENDS+=		p5-Net-IDN-Encode>=0:../../textproc/p5-Net-IDN-Encode
DEPENDS+=		p5-Net-IMAP-Simple>=0:../../mail/p5-Net-IMAP-Simple
DEPENDS+=		p5-Net-IP>=0:../../net/p5-Net-IP
DEPENDS+=		p5-Net-SMTPS>=0:../../mail/p5-Net-SMTPS
DEPENDS+=		p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay
DEPENDS+=		p5-Regexp-Common>=2013031301:../../textproc/p5-Regexp-Common
DEPENDS+=		p5-Socket6>=0.23:../../net/p5-Socket6
DEPENDS+=		p5-Test-File-ShareDir>=0:../../devel/p5-Test-File-ShareDir
DEPENDS+=		p5-URI>=0:../../www/p5-URI
DEPENDS+=		p5-XML-LibXML>=0:../../textproc/p5-XML-LibXML
TEST_DEPENDS+=		p5-Test-Exception>=0:../../devel/p5-Test-Exception
TEST_DEPENDS+=		p5-Test-File-ShareDir>=0:../../devel/p5-Test-File-ShareDir
TEST_DEPENDS+=		p5-Test-Output>=0:../../devel/p5-Test-Output

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Mail/DMARC/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
