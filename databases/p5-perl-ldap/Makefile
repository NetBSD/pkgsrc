# $NetBSD: Makefile,v 1.23 2004/04/25 17:22:29 snj Exp $
#

DISTNAME=     	perl-ldap-0.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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

.include "../../mk/bsd.prefs.mk"

.if defined(USE_SASL) && ${USE_SASL} == "YES"
DEPENDS+=	p5-Authen-SASL>=2.00:../../security/p5-Authen-SASL
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
.endif

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/perl-ldap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
