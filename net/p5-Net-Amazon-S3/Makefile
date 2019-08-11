# $NetBSD: Makefile,v 1.31 2019/08/11 13:22:16 wiz Exp $

DISTNAME=	Net-Amazon-S3-0.85
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-Amazon-S3
COMMENT=	Framework for accessing amazon.com via SOAP and XML/HTTP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Stream-Bulk>=0:../../net/p5-Data-Stream-Bulk
DEPENDS+=	p5-DateTime-Format-HTTP>=0:../../time/p5-DateTime-Format-HTTP
DEPENDS+=	p5-DateTime-Format-ISO8601>=0:../../time/p5-DateTime-Format-ISO8601
DEPENDS+=	p5-Digest-HMAC>=0:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Digest-MD5-File>=0:../../security/p5-Digest-MD5-File
DEPENDS+=	p5-libwww>=2:../../www/p5-libwww
DEPENDS+=	p5-LWP-UserAgent-Determined>=0:../../www/p5-LWP-UserAgent-Determined
DEPENDS+=	p5-Moose>=0.85:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Role-Parameterized-[0-9]*:../../devel/p5-MooseX-Role-Parameterized
DEPENDS+=	p5-MooseX-StrictConstructor>=0.16:../../devel/p5-MooseX-StrictConstructor
DEPENDS+=	p5-MooseX-Types-DateTime>=0.07:../../time/p5-MooseX-Types-DateTime
DEPENDS+=	p5-MooseX-Types-DateTime-MoreCoercions>=0.07:../../time/p5-MooseX-Types-DateTime-MoreCoercions
DEPENDS+=	p5-Regexp-Common>=0:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-Sub-Override>=0:../../devel/p5-Sub-Override
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-XML-LibXML>=0:../../textproc/p5-XML-LibXML

TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-MockTime-[0-9]*:../../time/p5-Test-MockTime
TEST_DEPENDS+=	p5-Test-LoadAllModules-[0-9]*:../../devel/p5-Test-LoadAllModules
#Warning: prerequisite File::Find::Rule 0 not found.
#Warning: prerequisite MIME::Types 0 not found.
#Warning: prerequisite Term::Encoding 0 not found.
#Warning: prerequisite Term::ProgressBar::Simple 0 not found.

REPLACE_PERL=	bin/s3cl

PERL5_PACKLIST= auto/Net/Amazon/S3/.packlist

post-install:
		(cd ${DESTDIR}; ${FIND} . -name \*.pm \( -perm 0555  -or -perm 0755 \) -exec ${CHMOD} -x '{}' \; )
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
