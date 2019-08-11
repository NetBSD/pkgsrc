# $NetBSD: Makefile,v 1.59 2019/08/11 13:18:35 wiz Exp $

DISTNAME=	perl-ldap-0.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	databases net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ldap.perl.org/
COMMENT=	Perl class to access LDAP servers
LICENSE=	${PERL5_LICENSE}

BUILD_DEFS+=	IPV6_READY

DEPENDS+=	p5-Convert-ASN1>=0.07:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-IO-Socket-SSL>=0.81:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-Text-Soundex-[0-9]*:../../textproc/p5-Text-Soundex
#DEPENDS+=	{perl>=5.8.0,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-URI>=1.10:../../www/p5-URI
DEPENDS+=	p5-XML-SAX-Writer-[0-9]*:../../textproc/p5-XML-SAX-Writer

MAKE_PARAMS+=	--skip	# skip CPAN auto installation of modules

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-perl-ldap
PKG_SUPPORTED_OPTIONS=	sasl inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
DEPENDS+=	p5-Authen-SASL>=2.00:../../security/p5-Authen-SASL
#DEPENDS+=	{perl>=5.8.0,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
.endif

.if !empty(PKG_OPTIONS:Minet6)
DEPENDS+=	p5-IO-Socket-INET6-[0-9]*:../../net/p5-IO-Socket-INET6
.endif

PERL5_PACKLIST=		auto/Net/LDAP/.packlist

post-extract:
	chmod a-x ${WRKSRC}/lib/Net/LDAP/DSML.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
