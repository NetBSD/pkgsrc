# $NetBSD: Makefile,v 1.1.1.1 2004/06/05 03:15:18 taca Exp $
#

DISTNAME=	Unicode-IMAPUtf7-2.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cpan.uwinnipeg.ca/module/Unicode::IMAPUtf7
COMMENT=	Perl extension to deal with IMAP UTF7

DEPENDS+=	p5-Unicode-String>=2.06:../../converters/p5-Unicode-String

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Unicode/IMAPUtf7/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
