# $NetBSD: Makefile,v 1.10 2001/09/27 23:17:54 jlam Exp $
#

DISTNAME=     	perl-ldap-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://perl-ldap.sourceforge.net/
COMMENT=	Perl class to access LDAP servers

DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Convert-ASN1-[0-9]*:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/perl-ldap/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
