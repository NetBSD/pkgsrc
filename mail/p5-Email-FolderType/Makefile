# $NetBSD: Makefile,v 1.22 2023/07/06 09:40:43 wiz Exp $

DISTNAME=	Email-FolderType-0.814
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Email-FolderType
COMMENT=	Perl 5 module to determine the type of a mail folder
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable

PERL5_PACKLIST=	auto/Email/FolderType/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
