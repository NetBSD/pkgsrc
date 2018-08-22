# $NetBSD: Makefile,v 1.20 2018/08/22 09:43:08 wiz Exp $

DISTNAME=	Unicode-IMAPUtf7-2.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	converters mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FA/FABPOT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unicode-IMAPUtf7/
COMMENT=	Perl extension to deal with IMAP UTF7

DEPENDS+=	p5-Unicode-String>=2.06:../../converters/p5-Unicode-String

PERL5_PACKLIST=		auto/Unicode/IMAPUtf7/.packlist

post-extract:
	chmod -R +rwx ${WRKSRC}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
