# $NetBSD: Makefile,v 1.1.1.1 2001/06/27 03:24:48 dogcow Exp $

DISTNAME=       perl-ldap-0.23
PKGNAME=        p5-Net-LDAP-0.23
CATEGORIES=     net perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=     dogcow@netbsd.org
HOMEPAGE=       http://perl-ldap.sourceforge.net/
COMMENT=        perl5 LDAP interface

DEPENDS+=	p5-Convert-ASN1-*:../../textproc/p5-Convert-ASN1

USE_PERL5=      # defined
PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/perl-ldap/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

