# $NetBSD: Makefile,v 1.20 2022/06/28 11:32:57 wiz Exp $

DISTNAME=	Net-LDAP-Class-0.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	databases devel net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Net-LDAP-Class
COMMENT=	Perl 5 module providing an object-relational mapper for Net::LDAP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=	p5-Net-LDAP-Batch-[0-9]*:../../devel/p5-Net-LDAP-Batch
DEPENDS+=	p5-Net-LDAP-SID-[0-9]*:../../devel/p5-Net-LDAP-SID
DEPENDS+=	p5-Rose-Object-[0-9]*:../../devel/p5-Rose-Object
DEPENDS+=	p5-perl-ldap-[0-9]*:../../databases/p5-perl-ldap

BUILD_DEPENDS+=	p5-Net-LDAP-Server-Test>=0.09:../../devel/p5-Net-LDAP-Server-Test

PERL5_PACKLIST=	auto/Net/LDAP/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
