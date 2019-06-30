# $NetBSD: Makefile,v 1.17 2019/06/30 20:16:15 nia Exp $

DISTNAME=	MIME-Lite-HTML-1.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MIME-Lite-HTML
COMMENT=	Perl5 module to transform a HTML page into a MIME-Lite mail
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MIME-Lite>=3.01:../../mail/p5-MIME-Lite
DEPENDS+=	p5-libwww>=5.805:../../www/p5-libwww
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=	auto/MIME/Lite/HTML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
