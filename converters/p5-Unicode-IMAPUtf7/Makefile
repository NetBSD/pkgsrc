# $NetBSD: Makefile,v 1.3 2004/12/20 11:30:56 grant Exp $
#

DISTNAME=	Unicode-IMAPUtf7-2.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters mail perl5
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
