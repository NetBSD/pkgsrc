# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:39 joerg Exp $
#

DISTNAME=	Net-LDAP-Server-0.3
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}
HOMEPAGE=	http://search.cpan.org/~aar/Net-LDAP-Server-0.3/

MAINTAINER=	he@NetBSD.org
COMMENT=	LDAP server side protocol handling

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Convert-ASN1-[0-9]*:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap

PERL5_PACKLIST=	auto/Net/LDAP/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
