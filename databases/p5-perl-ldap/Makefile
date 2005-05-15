# $NetBSD: Makefile,v 1.26 2005/05/15 17:12:09 seb Exp $
#

DISTNAME=     	perl-ldap-0.3202
PKGNAME=	p5-perl-ldap-0.32.02
SVR4_PKGNAME=	pldap
CATEGORIES=	databases net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://perl-ldap.sourceforge.net/
COMMENT=	Perl class to access LDAP servers

DEPENDS+=	p5-Convert-ASN1>=0.07:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-IO-Socket-SSL>=0.81:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-URI>=1.08:../../www/p5-URI
DEPENDS+=	p5-XML-SAX-[0-9]*:../../textproc/p5-XML-SAX

MAKE_PARAMS+=	--skip	# skip CPAN auto installation of modules

PKG_SUPPORTED_OPTIONS=	sasl
PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-perl-ldap
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
DEPENDS+=	p5-Authen-SASL>=2.00:../../security/p5-Authen-SASL
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
.endif

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/LDAP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
