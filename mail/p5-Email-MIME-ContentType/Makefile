# $NetBSD: Makefile,v 1.21 2019/08/11 13:21:32 wiz Exp $

DISTNAME=		Email-MIME-ContentType-1.022
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Email-MIME-ContentType
COMMENT=		Perl module for parsing a MIME Content-Type header
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Email/MIME/ContentType/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
