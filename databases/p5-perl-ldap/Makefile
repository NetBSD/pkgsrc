# $NetBSD: Makefile,v 1.1.1.1 1999/12/03 09:35:57 rh Exp $
#

PKGNAME=       	p5-perl-ldap-0.13
DISTNAME!=     	echo ${PKGNAME} | sed -e 's/^p5-//'
CATEGORIES=	databases net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pobox.com/~gbarr/perl-ldap/

DEPENDS+=	p5-Digest-MD5-*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Convert-BER-*:../../textproc/p5-Convert-BER
DEPENDS+=	p5-libwww-*:../../www/p5-libwww

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
