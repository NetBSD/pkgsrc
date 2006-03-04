# $NetBSD: Makefile,v 1.7 2006/03/04 21:29:06 jlam Exp $
#

DISTNAME=	Unicode-IMAPUtf7-2.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	converters mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/module/Unicode::IMAPUtf7
COMMENT=	Perl extension to deal with IMAP UTF7

DEPENDS+=	p5-Unicode-String>=2.06:../../converters/p5-Unicode-String

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Unicode/IMAPUtf7/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
