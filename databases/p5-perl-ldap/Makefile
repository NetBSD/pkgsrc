# $NetBSD: Makefile,v 1.7 2000/10/16 11:02:35 rh Exp $
#

DISTNAME=     	perl-ldap-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://perl-ldap.sourceforge.net/

DEPENDS+=	p5-XML-Parser-*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Digest-MD5-*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Convert-ASN1-*:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-libwww-*:../../www/p5-libwww

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/perl-ldap/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
