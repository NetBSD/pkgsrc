# $NetBSD: Makefile,v 1.3 2023/07/06 09:41:37 wiz Exp $

DISTNAME=	Encode-IMAPUTF7-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/Encode-IMAPUTF7
COMMENT=	Perl extension to deal with UTF-7 modification for IMAP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

PERL5_PACKLIST=		auto/Encode/IMAPUTF7/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
