# $NetBSD: Makefile,v 1.21 2023/07/06 09:40:43 wiz Exp $

DISTNAME=	Email-LocalDelivery-1.201
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Email-LocalDelivery
COMMENT=	Perl 5 module to deliver a piece of email - simply
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Email/LocalDelivery/.packlist

DEPENDS+=	p5-Email-FolderType>=0.7:../../mail/p5-Email-FolderType
DEPENDS+=	p5-Email-Simple>=1.998:../../mail/p5-Email-Simple
DEPENDS+=	p5-File-Path-Expand>=1.01:../../devel/p5-File-Path-Expand

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
