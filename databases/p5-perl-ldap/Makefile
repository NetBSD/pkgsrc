# $NetBSD: Makefile,v 1.13 2001/11/28 21:16:13 kleink Exp $
#

DISTNAME=     	perl-ldap-0.25
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	pldap
CATEGORIES=	databases net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://perl-ldap.sourceforge.net/
COMMENT=	Perl class to access LDAP servers

DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Convert-ASN1-[0-9]*:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:security/p5-IO-Socket-SSL

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/perl-ldap/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
