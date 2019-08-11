# $NetBSD: Makefile,v 1.22 2019/08/11 13:18:14 wiz Exp $

DISTNAME=	Unicode-IMAPUtf7-2.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	converters mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FA/FABPOT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Unicode-IMAPUtf7
COMMENT=	Perl extension to deal with IMAP UTF7

DEPENDS+=	p5-Unicode-String>=2.06:../../converters/p5-Unicode-String

PERL5_PACKLIST=		auto/Unicode/IMAPUtf7/.packlist

post-extract:
	chmod -R +rwx ${WRKSRC}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
