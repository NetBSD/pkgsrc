# $NetBSD: Makefile,v 1.4 2000/06/09 14:32:47 kleink Exp $
#

DISTNAME=     	perl-ldap-0.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://perl-ldap.sourceforge.net/

DEPENDS+=	p5-Digest-MD5-*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Convert-ASN1-*:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-libwww-*:../../www/p5-libwww

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
