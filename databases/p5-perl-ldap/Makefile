# $NetBSD: Makefile,v 1.2 1999/12/28 04:54:34 wiz Exp $
#

DISTNAME=     	perl-ldap-0.13
PKGNAME=       	${DISTNAME:S/^/p5-/}
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
