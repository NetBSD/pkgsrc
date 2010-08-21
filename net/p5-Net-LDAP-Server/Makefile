# $NetBSD: Makefile,v 1.6 2010/08/21 16:35:25 seb Exp $
#

DISTNAME=	Net-LDAP-Server-0.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-LDAP-Server/
COMMENT=	LDAP server side protocol handling

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Convert-ASN1-[0-9]*:../../textproc/p5-Convert-ASN1
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap

PERL5_PACKLIST=	auto/Net/LDAP/Server/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
