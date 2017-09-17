# $NetBSD: Makefile,v 1.18 2017/09/17 15:54:08 wiz Exp $

DISTNAME=		Email-MIME-ContentType-1.022
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Email-MIME-ContentType/
COMMENT=		Perl module for parsing a MIME Content-Type header
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Email/MIME/ContentType/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
